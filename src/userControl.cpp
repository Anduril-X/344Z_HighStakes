#include "lemlib/api.hpp" // IWYU pragma: keep
#include "userControl.h"
#include "pros/misc.h"
#include "robotConfig.h"

using namespace pros;

void userControl() {
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        // move the robot
        chassis.arcade(leftY, rightX);

		delay(20);  // Run for 20 ms then update
	}
}