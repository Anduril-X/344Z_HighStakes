#include "auton.h"
#include "autonSelector.h"
#include "compInitialize.h"
#include "liblvgl/llemu.hpp"

short shownAuton = 0;
short numberOfAutons = 5;
short autonSelection = -1; //default value to fail if no auton is selected


//Callback function for the right lcd button to cycle through the available autonomous routines
void rightButton() {
    if (autonSelection == -1) {
        if (shownAuton == numberOfAutons - 1) {
            shownAuton = 0;
        }
        else {
            shownAuton++;
        }
        pros::lcd::set_text(1, autons[shownAuton].c_str());
    }
    else {
        pros::lcd::set_text(2, "You have already selected an auton.");
    }
}


//Callback function for the left lcd button to cycle through the available autonomous routines
void leftButton() {
    if (autonSelection == -1) {
        if (shownAuton == 0) {
            shownAuton = numberOfAutons - 1;
        }
        else {
            shownAuton--;
        }
        pros::lcd::set_text(1, autons[shownAuton].c_str());
    }
    else {
        pros::lcd::set_text(2, "You have already selected an auton.");
    }
}


//Callback function for the center lcd button to select an autonomous routine
void centerButton() {
    if (autonSelection == -1) {
        autonSelection = shownAuton;
    }
    else {
        pros::lcd::set_text(2, "You have already selected an auton.");
    }
}