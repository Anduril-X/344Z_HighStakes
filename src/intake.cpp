#include "intake.h"
#include "robotConfig.h"

//Control for chain lift and intake
void intakeControl() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeMotor.move(105);
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
         intakeMotor.move(-105);
    }
    else {
        intakeMotor.brake();
    }
}