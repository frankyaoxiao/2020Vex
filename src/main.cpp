#include "main.h"


pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor LeftFrontMotor(1);
pros::Motor RightFrontMotor(2);
pros::Motor LeftBackMotor(3);
pros::Motor RightBackMotor(4);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

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
void competition_initialize() {}

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
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {



	while (true) {


		int LF = master.get_analog(ANALOG_LEFT_X) + master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_Y);
		int RF = master.get_analog(ANALOG_LEFT_X) - master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_Y);
		int LB = master.get_analog(ANALOG_LEFT_X) - master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_Y);
		int RB = master.get_analog(ANALOG_LEFT_X) + master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_Y);

		LeftFrontMotor.move(LF);
		RightFrontMotor.move(RF);
		LeftBackMotor.move(LB);
		RightBackMotor.move(RB);
		pros::delay(2);

	}
}
