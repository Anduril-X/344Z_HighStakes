#include "auton.h"
#include "autonSelector.h"
#include "robotConfig.h"

using namespace pros;

/*std::string autons[5] = {"name1", //auton1
                         "name2",  //auton2
                         "name3",  //auton3
                         "name4",  //auton4
                         "name5"};  //auton5*/

void auton() {
    chassis.setPose(0, 0, 0);
    // move 48" forwards
    chassis.moveToPoint(0, 24, 10000);
    /*//Run the ____ auton
    if (autonSelection == 0) {
7j
    }
    //Run the ____ auton
    else if (autonSelection == 1) {

    }
    //Run the ____ auton
    else if (autonSelection == 2) {
        
    }
    //Run the ____ auton
    else if (autonSelection == 3) {
        
    }
    //Run the ____ auton
    else if (autonSelection == 4) {
        
    }
    //Run the ____ auton
    else if (autonSelection == 5) {

    }
    //Run the ____ auton
    else if (autonSelection == 6) {
    
    }
    //Default in case no selection so the robot does not disqualify itself but also gets off the start line
    else {
        whole.move(25);
        delay(1000);
        whole.brake();
    }*/
}