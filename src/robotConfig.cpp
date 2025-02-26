#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "robotConfig.h"

using namespace pros;

//Controller
Controller controller = Controller(E_CONTROLLER_MASTER);

// Motor Groups for drivetrain
MotorGroup leftSide = MotorGroup({-10, 20, -19}, MotorGearset::blue);
MotorGroup rightSide = MotorGroup({3, -4, 5}, MotorGearset::blue);
MotorGroup whole = MotorGroup({0, -0, 0, -0, 0, -0}, MotorGearset::blue);

//Motor for chain lift and intake
Motor intakeMotor = Motor(-7, MotorGearset::blue);

//Motor and sensor for the lady brown
Motor ladyBrown = Motor(-1, MotorGearset::red);
Rotation rotSensor = Rotation(-9);

//Solenoid for mobile goal clamp
adi::DigitalOut clampSolenoid = adi::DigitalOut(7);

//Solenoid for Corner Clearer
adi::DigitalOut cornerClearer = adi::DigitalOut(8);

//Solenoid for tipper
adi::DigitalOut tipper = adi::DigitalOut(6);

// drivetrain settings
lemlib::Drivetrain drivetrain = lemlib::Drivetrain(&leftSide, // left motor group
                                                  &rightSide, // right motor group
                                                  13.5, // 13.5 inch track width
                                                  lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                                                  450, // drivetrain rpm is 450
                                                  2 // horizontal drift is 2 (for now)
);

//Inertial Sensor
Imu imu = Imu(6);

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
                                                                           0, // anti windup
                                                                           0, // small error range, in inches
                                                                           0, // small error range timeout, in milliseconds
                                                                           0, // large error range, in inches
                                                                           0, // large error range timeout, in milliseconds
                                                                           0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angularController = lemlib::ControllerSettings(2, // proportional gain (kP)
                                                                           0, // integral gain (kI)
                                                                           10, // derivative gain (kD)
                                                                           0, // anti windup
                                                                           0, // small error range, in degrees
                                                                           0, // small error range timeout, in milliseconds
                                                                           0, // large error range, in degrees
                                                                           0, // large error range timeout, in milliseconds
                                                                           0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve = lemlib::ExpoDriveCurve(3, // joystick deadband out of 127
                                                               3, // minimum output where drivetrain will move out of 127
                                                               1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve = lemlib::ExpoDriveCurve(3, // joystick deadband out of 127
                                                            3, // minimum output where drivetrain will move out of 127
                                                            1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis = lemlib::Chassis(drivetrain,
                                          lateralController,
                                          angularController,
                                          sensors,
                                          &throttleCurve, 
                                          &steerCurve
);