#include "main.h"

#ifndef GLOBALS
#define GLOBALS

// auto flags
extern bool ALLIANCE;
extern bool STACK;
extern bool POSITION;

// vision
// extern int VISION_PORT;
// extern int TORTEX_YELLOW;
// extern pros::Vision camera;

// controllers
extern pros::Controller driver;
extern pros::Controller partner;

// drive motors
extern int FRONT_LEFT_MOTOR_PORT;
extern int FRONT_RIGHT_MOTOR_PORT;
extern int BACK_LEFT_MOTOR_PORT;
extern int BACK_RIGHT_MOTOR_PORT;

// roller motors
extern int LEFT_ROLLER_MOTOR_PORT;
extern int RIGHT_ROLLER_MOTOR_PORT;

// intake motor
extern int INTAKE_MOVER_MOTOR_PORT;

// chassis
extern okapi::ChassisControllerIntegrated drive;
extern okapi::ChassisControllerIntegrated linear;
extern okapi::ChassisControllerIntegrated rollers;

#endif
