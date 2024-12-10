#include "lemlib/api.hpp" // IWYU pragma: keep
#include "compInitialize.h"
#include "autonSelector.h"
#include "auton.h"
#include "pros/llemu.hpp"


using namespace pros;

void compInitialize() {
    lcd::initialize(); // initialize brain screen
    //Register callbacks for button presses on the brain screen
    lcd::register_btn0_cb(leftButton);
    lcd::register_btn1_cb(centerButton);
    lcd::register_btn2_cb(rightButton);
    lcd::set_text(1, autons[shownAuton].c_str());
}