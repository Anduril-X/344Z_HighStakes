#include "ladyBrown.h"
#include "pros/misc.h"
#include "robotConfig.h"


//Set lady brown to scoring position
void setPos() {
    if (rotSensor.get_position() > 2810) {
        while (rotSensor.get_position() > 2810) {
            ladyBrown.move(-127);
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
                break;
            }
        }
    }
    else if (rotSensor.get_position() < 2710) {
        while (rotSensor.get_position() < 2710) {
            ladyBrown.move(127);
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
                break;
            }
        }
    }
    ladyBrown.brake();
}

//Set lady brown back to starting position
void resetPos() {
    while (rotSensor.get_position() > 115) {
        ladyBrown.move(-70);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            break;
        }
    }
    ladyBrown.brake();
}

//Macro to grab ring off and set the position to the scoring position
void scoreMacro() {
    while(rotSensor.get_position() < 13380) {
        ladyBrown.move(127);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            break;
        }
    }
    ladyBrown.brake();
}