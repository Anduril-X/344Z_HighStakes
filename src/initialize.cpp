#include "lemlib/api.hpp" // IWYU pragma: keep
#include "initialize.h"
#include "robotConfig.h"
#include "compInitialize.h"
#include "pros/llemu.hpp"

using namespace pros;


void myInitialize() {
    lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    /*Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            lcd::print(0, "X: %f", chassis.getPose().x); // x
            lcd::print(1, "Y: %f", chassis.getPose().y); // y
            lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            delay(20);
        }
    });*/
}