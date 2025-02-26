#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/chassis.hpp"

using namespace pros;

//Controller
extern Controller controller;

// Motor Groups for drivetrain
extern MotorGroup leftSide;
extern MotorGroup rightSide;
extern MotorGroup whole;

//Motor for chain lift and intake
extern Motor intakeMotor;

//Motor and sensor for the lady brown
extern Motor ladyBrown;
extern Rotation rotSensor;

//Solenoid for mobile goal clamp
extern adi::DigitalOut clampSolenoid;

//Solenoid for Corner Clearer
extern adi::DigitalOut cornerClearer;

//Solenoid for tipper
extern adi::DigitalOut tipper;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

//Inertial Sensor
extern Imu imu;

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