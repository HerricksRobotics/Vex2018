#pragma config(Sensor, in1,    liftAngle,      sensorPotentiometer)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightArm,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           mobileLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           mobileLift2,   tmotorVex393_MC29, openLoop, reversed)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void moveForward(int speed) {
	motor[leftFront] = speed;
	motor[leftBack] = speed;
	motor[rightFront] = speed;
	motor[rightBack] = speed;
}

void liftArm(int speed) {
	motor[leftArm] = speed;
	motor[rightArm] = speed;
}

void liftMobileArm(int speed) {
  motor[mobileLift] = speed;
  motor[mobileLift2] = speed;
}
task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int grabberSpeed;
	int mobileSpeed;
	//Keep Grabber on the whole time
	motor[frontMotor] = 127;
	//Move Arm back for Preload
	liftArm(-60);
	wait1Msec(1000);
	liftArm(0);

	//Lower Mobile Goal Lift
	liftMobileArm(127);
	wait1Msec(800);
	liftMobileArm(0);

	//Move Forward Towards Mobile Goal
	moveForward(80);
	wait1Msec(2000);
	moveForward(0);

	//Raise Mobile Goal Lift
	liftMobileArm(-127);
	wait1Msec(800);
	liftMobileArm(0);

	//Stack Preload
	liftArm(60);
	wait1Msec(1000);
	liftArm(0);

	//Move Backward
	moveForward(-80);
	wait1Msec(2000);
	moveForward(0);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop
	int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int grabberSpeed;
	int mobileSpeed;
  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    //Controls Right Front Wheel
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch3];
		}
		//Controls Left Front Wheel
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch2];
		}
		//Controls arm movement
		if (vexRT[Btn6UXmtr2]==1) {
			armBaseSpeed = -60;
			grabberSpeed = 0;
		}
		else if (vexRT[Btn6DXmtr2]==1) {
			armBaseSpeed = 60;
			//grabberSpeed = -30;
		}
		else {
			armBaseSpeed = 0;
			grabberSpeed = 0;
		}
		//Controls pinchers movement
		if (vexRT[Btn8UXmtr2]==1)
		{
			grabberSpeed = 127;
		}
		else if (vexRT[Btn8DXmtr2]==1)
		{
			grabberSpeed = -127;
		}
		else {
			grabberSpeed = 0;
		}
		if (vexRT[Btn5UXmtr2]==1) {
			mobileSpeed = 127;
		}
		else if (vexRT[Btn5DXmtr2]==1) {
			mobileSpeed = -127;
		}
		else {
			mobileSpeed = 0;
		}
		motor[leftFront] = leftSpeed;
		motor[leftBack] = leftSpeed;
		motor[rightFront] = rightSpeed;
		motor[rightBack] = rightSpeed;
		motor[rightArm] = armBaseSpeed;
		motor[leftArm] = armBaseSpeed;
		motor[frontMotor] = grabberSpeed;
		motor[mobileLift] = mobileSpeed;
		motor[mobileLift2] = mobileSpeed;
  }
}
