#include "lemlib/api.hpp" // IWYU pragma: keep
#include "userControl.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "robotConfig.h"
#include "intake.h"
#include "mobileGoals.h"
#include "ladyBrown.h"
#include "arms.h"

using namespace pros;

void userControl() {
    rotSensor.set_position(100);
    ladyBrown.set_brake_mode(MotorBrake::hold);
    int number;
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        // move the robot
        chassis.arcade(leftY, rightX);

        //Control for chain lift and intake
        intakeControl();

        //Mobile goal clamp toggle control
        mogoToggle();

        //Control for tipper
        tipperToggle();

        //Control for clearer
        clearerToggle();

        //Control for the lady brown
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            scoreMacro();
        }
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            setPos();
        }
        else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
            resetPos();
        }
        else if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
            number = rotSensor.get_position();
            std::string temp_string = std::to_string(number);
            const char* cstring = temp_string.c_str();
            controller.print(1,1, cstring);
        }
        /*if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && rotSensor.get_position() < 19380) {
            ladyBrown.move(70);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            ladyBrown.move(-70);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && rotSensor.get_position() < 19380) {
            ladyBrown.move(25);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            ladyBrown.move(-25);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            ladyBrown.set_brake_mode(MotorBrake::coast);
            ladyBrown.brake();
        }
        else {
            ladyBrown.set_brake_mode(MotorBrake::hold);
            ladyBrown.brake();
        }*/


		delay(20);  // Run for 20 ms then update
	}
}