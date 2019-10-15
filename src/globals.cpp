#include "main.h"

// auto flags
bool ALLIANCE = false; // red false, blue true
bool STACK = false; // big false, small true
bool POSITION = false; // false far, true near

// vision
// int VISION_PORT = 11;
// int TORTEX_YELLOW = 2;
// pros::Vision camera(VISION_PORT);

// controllers
pros::Controller driver = pros::E_CONTROLLER_MASTER;
pros::Controller partner = pros::E_CONTROLLER_PARTNER;

// drive motors
int FRONT_LEFT_MOTOR_PORT = 1;
int FRONT_RIGHT_MOTOR_PORT = 10;
int BACK_LEFT_MOTOR_PORT = 2;
int BACK_RIGHT_MOTOR_PORT = 9;

// roller motors
int LEFT_ROLLER_MOTOR_PORT = 7;
int RIGHT_ROLLER_MOTOR_PORT = 8;

// intake
int INTAKE_MOVER_MOTOR_PORT = 5;

// chassis
using namespace okapi::literals;
okapi::ChassisControllerIntegrated drive = okapi::ChassisControllerFactory::create(
    {FRONT_LEFT_MOTOR_PORT, BACK_LEFT_MOTOR_PORT}, {FRONT_RIGHT_MOTOR_PORT, BACK_RIGHT_MOTOR_PORT},
    okapi::AbstractMotor::gearset::green,
    {4_in, 14.55_in}
);
okapi::ChassisControllerIntegrated rollers = okapi::ChassisControllerFactory::create(
    LEFT_ROLLER_MOTOR_PORT, RIGHT_ROLLER_MOTOR_PORT,
    okapi::AbstractMotor::gearset::green
); 