#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/chassis.hpp"
#include "pros/motor_group.hpp"
#include "robotConfig.h"

//Controller
pros::Controller controller = pros::Controller(pros::E_CONTROLLER_MASTER);

// Motor Groups
pros::MotorGroup leftSide = pros::MotorGroup({1, 2, 3}, pros::MotorGearset::blue);
pros::MotorGroup rightSide = pros::MotorGroup({4, 5, 6}, pros::MotorGearset::blue);

// drivetrain settings
lemlib::Drivetrain drivetrain = lemlib::Drivetrain(&leftSide, // left motor group
                                                  &rightSide, // right motor group
                                                  13.5, // 13.5 inch track width
                                                  lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                                                  450, // drivetrain rpm is 450
                                                  2 // horizontal drift is 2 (for now)
);

//Inertial Sensor
pros::Imu imu = pros::Imu(10);

//Lemlib entire configuration for tracking
lemlib::OdomSensors sensors = lemlib::OdomSensors(nullptr, // vertical tracking wheel 1, set to nullptr as we are using IMEs
                                                  nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                                                  nullptr, // horizontal tracking wheel 1, set to nullptr as we are using IMEs
                                                  nullptr, // horizontal tracking wheel 2, set to nullptr as we are using IMEs
                                                  &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateralController = lemlib::ControllerSettings(10, // proportional gain (kP)
                                                                           0, // integral gain (kI)
                                                                           3, // derivative gain (kD)
                                                                           3, // anti windup
                                                                           1, // small error range, in inches
                                                                           100, // small error range timeout, in milliseconds
                                                                           3, // large error range, in inches
                                                                           500, // large error range timeout, in milliseconds
                                                                           20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularController = lemlib::ControllerSettings(2, // proportional gain (kP)
                                                                           0, // integral gain (kI)
                                                                           10, // derivative gain (kD)
                                                                           3, // anti windup
                                                                           1, // small error range, in degrees
                                                                           100, // small error range timeout, in milliseconds
                                                                           3, // large error range, in degrees
                                                                           500, // large error range timeout, in milliseconds
                                                                           0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve = lemlib::ExpoDriveCurve(3, // joystick deadband out of 127
                                                               10, // minimum output where drivetrain will move out of 127
                                                               1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve = lemlib::ExpoDriveCurve(3, // joystick deadband out of 127
                                                            10, // minimum output where drivetrain will move out of 127
                                                            1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain,
                        lateralController,
                        angularController,
                        sensors,
                        &throttleCurve, 
                        &steerCurve
);