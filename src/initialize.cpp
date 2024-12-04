#include "lemlib/api.hpp" // IWYU pragma: keep
#include "initialize.h"
#include "pros/llemu.hpp"
#include "robotConfig.h"

using namespace pros;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		lcd::set_text(2, "I was pressed!");
	} else {
		lcd::clear_line(2);
	}
}


void myInitialize() {
	lcd::register_btn1_cb(on_center_button);

	lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            lcd::print(0, "X: %f", chassis.getPose().x); // x
            lcd::print(1, "Y: %f", chassis.getPose().y); // y
            lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            delay(20);
        }
    });
}