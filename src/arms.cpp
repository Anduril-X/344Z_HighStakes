#include "arms.h"
#include "pros/misc.h"
#include "robotConfig.h"

bool tipperDown = false;

//control for mobile goal clamp
void tipperToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
    tipperDown = !tipperDown; // toggle piston state
    tipper.set_value(tipperDown);
  }
}

bool clearerDown = false;

//control for mobile goal clamp
void clearerToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    clearerDown = !clearerDown; // toggle piston state
    cornerClearer.set_value(clearerDown);
  }
}
