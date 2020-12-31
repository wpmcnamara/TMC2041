/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper motor.
 */

#include <TMC2041.h>

#define EN_PIN           21 // Enable
#define DIR_PIN          22 // Direction
#define STEP_PIN         23 // Step
#define CS_PIN           10 // Chip select


#define R_SENSE 0.27f // Match to your driver
                     // SilentStepStick series use 0.11
                     // UltiMachine Einsy and Archim2 boards use 0.2
                     // Panucatt BSD2660 uses 0.1
                     // Watterott TMC5160 uses 0.075

TMC2041 driver(CS_PIN, R_SENSE, -1); 

// You can define starting values here:
struct {
    uint8_t blank_time = 24;        // [16, 24, 36, 54]
    uint8_t off_time = 3;           // [1..15]
    uint8_t hysteresis_start = 1;   // [1..8]
    int8_t hysteresis_end = 12;     // [-3..12]
} config;

IntervalTimer step;
void initPins();

void motorStep() {
    static bool toggle=0;
    digitalWrite(STEP_PIN, toggle);
    toggle=!toggle;
    //digitalWrite(STEP_PIN, 0);
}

void reportCurrentSettings() {
    Serial.print("Off time = ");
    Serial.flush();
    Serial.print(config.off_time);
    Serial.flush();
    Serial.print(" Hysteresis end = ");
    Serial.flush();
    Serial.print(config.hysteresis_end);
    Serial.flush();
    Serial.print(" Hysteresis start = ");
    Serial.flush();
    Serial.println(config.hysteresis_start);
    Serial.flush();
}

void setup() {
    initPins();
    driver.begin();
    Serial.begin(115200);
    while (!Serial) delay(250);
    for (uint8_t i = 0; i < 60; i++) { Serial.print('.'); Serial.flush(); delay(250); }
    Serial.println(F("Starting calibration of TMC spreadCycle parameters."));
    Serial.flush();
    delay(250);
    Serial.println(F("This example by default uses X axis driver on a RAMPS1.4."));
    Serial.flush();
     delay(250);
    Serial.println(F("First make sure your serial terminal sends newline ending only!"));
    Serial.flush();
     delay(250);

    Serial.println(F("\nThen make sure the belt is disconnected"));
    Serial.flush();
     delay(250);
    Serial.println(F("as we will not respect endstops or physical limits"));
    Serial.flush();
     delay(250);
    while(1) {
        Serial.println(F("Is the belt disconnected? Send 'yes' to confirm."));
        Serial.flush();
         delay(250);
        while(!Serial.available());
        String yn = Serial.readStringUntil('\n');
        Serial.println(yn);
        if (yn == "yes") {
            break;
        } else {
            Serial.println(F("Belt still connected."));
            Serial.flush();
             delay(250);
            Serial.println(F("Please disconnect belt."));
            Serial.flush();
             delay(250);
        };
    }

    Serial.println(F("\nNow make sure the driver has 12V (or greater) power turned on."));
    Serial.flush();
    delay(250);
    while(1) {
        Serial.println(F("Is VMOT power on? Send 'yes' to confirm"));
        Serial.flush();
        delay(250);
        while(!Serial.available());
        String yn = Serial.readStringUntil('\n');
        Serial.println(yn);
        if (yn == "yes") {
            break;
        } else {
            Serial.println(F("Please turn on power to the driver."));
            Serial.flush();
            delay(250);
        };
    }

    Serial.print(F("\nTesting connection..."));
    Serial.flush();
    delay(250);
    /*
    uint8_t result = driver.test_connection();
    if (result) {
        Serial.println(F("failed!"));
        Serial.print(F("Likely cause: "));
        switch(result) {
            case 1: Serial.println(F("loose connection")); break;
            case 2: Serial.println(F("Likely cause: no power")); break;
        }
        Serial.println(F("Fix the problem and reset board."));
        abort();
    }
    */
    Serial.println(F("OK"));
    Serial.flush();
    delay(250);
    //driver.push();
    driver.microsteps(0, 256);
    driver.irun(0, 10);
    driver.ihold(0, 10);
    //driver.vsense(0);

    Serial.print(F("Setting driver blank time to "));
    Serial.flush();
    delay(250);
    Serial.print(config.blank_time);
    Serial.flush();
    delay(250);
    Serial.println(F(" cycles."));
    Serial.flush();
    delay(250);
    driver.tbl(config.blank_time);
    Serial.flush();
    delay(250);
    Serial.print(F("Setting driver off time to "));
    Serial.flush();
    delay(250);
    Serial.println(config.off_time);
    Serial.flush();
    delay(250);
    driver.toff(0, config.off_time);
    Serial.flush();
    delay(250);

    Serial.print(F("Setting hysteresis end value to "));
    Serial.flush();
    delay(250);
    Serial.println(config.hysteresis_end);
    Serial.flush();
    delay(250);
    driver.hend(config.hysteresis_end);
    Serial.flush();
    delay(250);
    Serial.print(F("Setting hysteresis start value to "));
    Serial.flush();
    delay(250);
    Serial.println(config.hysteresis_start);
    Serial.flush();
    delay(250);
    driver.hstrt(config.hysteresis_start);
    Serial.flush();
    delay(250);
    Serial.print(F("Effective hysteresis = "));
    Serial.flush();
    delay(250);
    Serial.print(config.hysteresis_end);
    Serial.flush();
    delay(250);
    Serial.print(F(" + "));
    Serial.flush();
    delay(250);
    Serial.print(config.hysteresis_start);
    Serial.flush();
    delay(250);
    Serial.print(F(" = "));
    Serial.flush();
    delay(250);
    Serial.println(config.hysteresis_end + config.hysteresis_start);
    Serial.flush();
    delay(250);
    Serial.println(F("\nNow we start decreasing the hysteresis end setting."));
    Serial.flush();
    delay(250);
    Serial.println(F("You should first hear your motor making clearly audible noise."));
    Serial.flush();
    delay(250);
    Serial.println(F("As we tune the timings the noise will get higher pitched."));
    Serial.flush();
    delay(250);
    Serial.println(F("When the noise is no longer audible we have reached a good setting."));
    Serial.flush();
    delay(250);
    Serial.println(F("You can tune the setting by sending - (minus) character"));
    Serial.flush();
    delay(250);
    Serial.println(F("or you can go back to previous parameter by sending + (plus) character."));
    Serial.flush();
    delay(250);
    Serial.println(F("Sending = (equal) character move to the next phase."));
    Serial.flush();
    delay(250);
    digitalWrite(EN_PIN, LOW);
    while (driver.cur_a_scaled(0) < 240) { // Use cur_b if measuring from B coil
        digitalWrite(STEP_PIN, HIGH);
        digitalWrite(STEP_PIN, LOW);
        delay(3);
        Serial.printf("version=%d, cur_a=%d, DRV_STATUS=%d, MSCNT=%d\n", driver.version(0), driver.cur_a_scaled(0), driver.DRV_STATUS(0), driver.MSCNT(0) );
    }
    delay(500);
    //step.begin(&motorStep, 10);
    while(1) {
        if (Serial.available() > 0) {
            uint8_t c = Serial.read();
            if (c == '+') {
                if (config.hysteresis_end == 12) Serial.println(F("Reached MAX setting already!"));
                else {
                    config.hysteresis_end++;
                    reportCurrentSettings();
                    driver.hend(0, config.hysteresis_end);
                }
            } else if (c == '-') {
                if (config.hysteresis_end == -3) Serial.println(F("Reached MIN setting already!"));
                else {
                    config.hysteresis_end--;
                    reportCurrentSettings();
                    driver.hend(0, config.hysteresis_end);
                }
            }
            else if (c == '=') break;
        }
    }

    Serial.print(F("Final effective hysteresis = "));
    Serial.print(config.hysteresis_end);
    Serial.print(F(" + "));
    Serial.print(config.hysteresis_start);
    Serial.print(F(" = "));
    Serial.println(config.hysteresis_end + config.hysteresis_start);
    Serial.println(F("Your configuration parameters in Marlin are:"));
    Serial.print(F("#define CHOPPER_TIMING { "));
    Serial.print(config.off_time);
    Serial.print(F(", "));
    Serial.print(config.hysteresis_end);
    Serial.print(F(", "));
    Serial.print(config.hysteresis_start);
    Serial.println(F(" }"));
}

void initPins() {
    pinMode(EN_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(CS_PIN, OUTPUT);
    pinMode(MISO, INPUT_PULLUP);
    digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
    digitalWrite(DIR_PIN, LOW); //LOW or HIGH
    digitalWrite(STEP_PIN, LOW);
    digitalWrite(CS_PIN, HIGH);
    //SPI.begin();
}

void loop() {}
