#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/chassis.hpp"

//Controller
extern pros::Controller controller;

// Motor Groups
extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

//Inertial Sensor
extern pros::Imu imu;

//Lemlib entire configuration for tracking
extern lemlib::OdomSensors sensors;

// lateral PID controller
extern lemlib::ControllerSettings lateralController;

// angular PID controller
extern lemlib::ControllerSettings angularController;

// input curve for throttle input during driver control
extern lemlib::ExpoDriveCurve throttleCurve;

// input curve for steer input during driver control
extern lemlib::ExpoDriveCurve steerCurve;

// create the chassis
extern lemlib::Chassis chassis;