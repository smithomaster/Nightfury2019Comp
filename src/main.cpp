#include "main.h"
#include "globals.hpp"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_alliance_button () {
    if(ALLIANCE == false){
        ALLIANCE = true;
        pros::lcd::print(0, "ALLIANCE (BTN 1): BLUE");
    }
    else if(ALLIANCE == true){
        ALLIANCE = false;
        pros::lcd::print(0, "ALLIANCE (BTN 1): RED");
    }
}
void on_position_button()
{
    if(POSITION == false){
        POSITION = true;
        pros::lcd::print(1, "POSITION (BTN 2): NEAR");
    }
    else if (POSITION == true) {
        POSITION = false;
        pros::lcd::print(1, "POSITION (BTN 2): FAR");
    }
}
void on_stack_button()
{
    if (STACK == false)
    {
        STACK = true;
        pros::lcd::print(2, "STACK (BTN 3): SMALL");
    }
    else if (STACK == true)
    {
        STACK = false;
        pros::lcd::print(2, "STACK (BTN 3): BIG");
    }
}

void releaseCubesAuto(){
    pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(50);
    pros::delay(2000);
    rollers.forward(-2);
    pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(0);
    rollers.stop();
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::lcd::initialize();
    pros::lcd::print(0, "ALLIANCE (BTN 1): RED");
    pros::lcd::print(1, "POSITION (BTN 2): FAR");
    pros::lcd::print(2, "STACK (BTN 3): BIG");
    pros::lcd::print(4, "PEMBROKE PEMBOTS 12223C");
    pros::lcd::print(7, "GOOD LUCK, TEAM!");
    pros::lcd::register_btn0_cb(on_alliance_button);
    pros::lcd::register_btn1_cb(on_position_button);
    pros::lcd::register_btn2_cb(on_stack_button);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    drive.setMaxVelocity(50);
    rollers.setMaxVelocity(10);
    using namespace okapi;
    rollers.forward(30);
    if (ALLIANCE == false){ // RED
        if (STACK == false) { // BIG
            if (POSITION == false){ // FARpr
                drive.moveDistance(2_ft);
                rollers.stop();
                drive.turnAngle(-180_deg);
                drive.moveDistance(2_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(2.5_ft);
                releaseCubesAuto();
                drive.moveDistance(-2_ft);
            } if (POSITION == true){ // NEAR
                drive.moveDistance(1_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(2_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(1.5_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(2_ft);
                pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(40);
                pros::delay(2000);
                pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(0);
                rollers.forward(-40);
            }
        }
        if (STACK == true) { // SMALL
            if (POSITION == false){ // FAR
                drive.moveDistance(3_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(1_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(3_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(2_ft);
                releaseCubesAuto();
                rollers.forward(-40);
            } if (POSITION == true){ // NEAR
                drive.moveDistance(3_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(1_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(2_ft);
                releaseCubesAuto();
                rollers.forward(-40);
            }
        }
    }
    if (ALLIANCE == true){ // BLUE
        if (STACK == false) { // BIG
            if (POSITION == false){ // FAR
                drive.moveDistance(2_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(3.5_ft);
                rollers.stop();
                drive.turnAngle(90_deg);
                drive.moveDistance(1.5_ft);
                releaseCubesAuto();
                drive.moveDistance(-1.5_ft);
            } if (POSITION == true){ // NEAR
                drive.moveDistance(1_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(2_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(1.5_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(2_ft);
                releaseCubesAuto();
                rollers.forward(-40);
            }
        }
        if (STACK == true) { // SMALL
            if (POSITION == false){ // FAR
                drive.moveDistance(3_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(1_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(3_ft);
                drive.turnAngle(90_deg);
                drive.moveDistance(2_ft);
                releaseCubesAuto();
                rollers.forward(-40);
            } if (POSITION == true){ // NEAR
                drive.moveDistance(3_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(1_ft);
                drive.turnAngle(-90_deg);
                drive.moveDistance(2_ft);
                releaseCubesAuto();
                rollers.forward(-40);
            }
        }
    }
    rollers.stop();}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *og
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    intake_mover_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    drive.setMaxVelocity(75);
    int left = 0;
    int right = 0;
	while(true){
        right = driver.get_analog(ANALOG_RIGHT_Y);
        left = driver.get_analog(ANALOG_LEFT_Y);
        right = right / 127;
        left = left / 127;
		drive.tank(left, right);
		if (driver.get_digital(DIGITAL_R2)){
			rollers.forward(63.5);
		} else if (driver.get_digital(DIGITAL_X)){
			rollers.forward(-12);
        } else if (driver.get_digital(DIGITAL_B)){
            rollers.forward(-1);
        }
        else {
			rollers.stop();
		}
		
		if (driver.get_digital(DIGITAL_L2)){ // push forwards
			pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(100);
		} else if (driver.get_digital(DIGITAL_L1)){ // move back
			pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(-100);
		} else {
			pros::Motor(INTAKE_MOVER_MOTOR_PORT).move(0);
		}
		pros::delay(2);
	}
}
