#include "ladyBrown.h"
#include "pros/misc.h"
#include "robotConfig.h"


//Set lady brown to scoring position
void setPos() {
    if (rotSensor.get_position() > 5500) {
        while (rotSensor.get_position() > 5500) {
            ladyBrown.move(-70);
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
                break;
            }
        }
    }
    else if (rotSensor.get_position() < 3950) {
        while (rotSensor.get_position() < 3950) {
            ladyBrown.move(70);
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
    intakeMotor.move(-40);
    delay(70);
    intakeMotor.brake();
    while(rotSensor.get_position() < 15400) {
        ladyBrown.move(70);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            break;
        }
    }
    ladyBrown.brake();
}