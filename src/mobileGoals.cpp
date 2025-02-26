#include "mobileGoals.h"
#include "pros/misc.h"
#include "robotConfig.h"

bool clampState = false;

//control for mobile goal clamp
void mogoToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    clampState = !clampState; // toggle piston state
    clampSolenoid.set_value(clampState);
  }
}