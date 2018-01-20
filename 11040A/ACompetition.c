#pragma config(Sensor, in1,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  lights,         sensorLEDtoVCC)
#pragma config(Motor,  port1,           rightFront,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port3,           rightMid,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           liftArms,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftBBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftMid,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftFront,     tmotorVex393_HBridge, openLoop, reversed)
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

	SensorType[in2] = sensorNone;
	wait1Msec(1000);
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise
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
void leftDrive(short speed)
{
	motor[leftFront] = speed;
	motor[leftMid] = speed;
	motor[leftBack] = speed;
	motor[leftBBack] = speed;
}

void rightDrive(short speed)
{
	motor[rightFront] = speed;
	motor[rightMid] = speed;
	motor[rightBack] = speed;
	motor[rightBBack] = speed;
}
void moveForward(short speed) {
	leftDrive(speed);
	rightDrive(speed);
}


task autonomous()
{
	short leftSpeed;
	short rightSpeed;
	SensorValue[gyro] = 0; //positive counterclockwise
	SensorValue[rightEncoder] = 0;

	//Lower the mobile goal carrier
	motor[liftArms] = -127;
	wait1Msec(1000);
	motor[liftArms] = 0;

	//Move forward to pick up mobile goal
	while ( (4 * PI * (SensorValue[rightEncoder] / 360) ) < 28 ) {
		moveForward(70);
	}
	moveForward(0);

	//Raise the mobile goal carrier
	motor[liftArms] = 127;
	wait1Msec(1500);
	motor[liftArms] = 0;

	//Move backward
	while ( (4 * PI * (SensorValue[rightEncoder] / 360) ) > 0 ) {
		moveForward(-50);
	}
	moveForward(0);

	//Turn left by 120 degrees
	while (abs(SensorValue[gyro]) < 1350) {
		rightDrive(50);
		motor[leftFront] = -50;
		motor[leftMid] = -50;
		motor[leftBack] = -50;
		motor[leftBBack] = -50;
	}
	rightDrive(0);
	motor[leftFront] = 0;
	motor[leftMid] = 0;
	motor[leftBack] = 0;
	motor[leftBBack] = 0;

	SensorValue[rightEncoder] = 0;
	//Move forward a little bit
	while ( ( 4 * PI * (SensorValue[rightEncoder] / 360) ) < 10) {
		moveForward(50);
	}
	moveForward(0);

	SensorValue[gyro] = 0;

	//Turn towards 20 point zone
	while (abs(SensorValue[gyro]) < 480) {
		rightDrive(80);
		motor[leftFront] = -80;
		motor[leftMid] = -80;
		motor[leftBack] = -80;
		motor[leftBBack] = -80;
	}
	rightDrive(0);
	motor[leftFront] = 0;
	motor[leftMid] = 0;
	motor[leftBack] = 0;
	motor[leftBBack] = 0;

	//Max speed into 20 Point Zone
	moveForward(100);
	wait1Msec(2000);
	moveForward(0);

	//Lower the mobile goal base
	motor[liftArms] = -127;
	wait1Msec(1000);
	motor[liftArms] = 0;

	//Move backward
	moveForward(-100);
	wait1Msec(1000);
	moveForward(0);
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
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

 	short leftSpeed;
	short rightSpeed;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;


	while(true)
	{
		/*				!!!		DRIVE CONTROLS		!!!
		*/
		//To control the left side using channel 3
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch3];
		}

		//To control the right side using channel 2
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch2];
		}

		leftDrive(leftSpeed);
		rightDrive(rightSpeed);

		/*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

		Pressing Button 6U should bring the mobile goal carrier in
		Pressing Button 6D should bring the mobile goal carrier out

		When contracted, pot = 4095
		When extended, pot = 2410
		*/
		if(vexRT[Btn6U] == 1 /*&& SensorValue[armLift] <4095*/)
		{
			motor[liftArms] = 127;
		}
		else if(vexRT[Btn6D] == 1 /*&& SensorValue[armLift] > 2501 */)
		{
			motor[liftArms] = -127;
		}
		else
		{
			motor[liftArms] = 0;
		}

		//light control (if getting one... VEX inverse the controls... idk y)
		//turning light on (0 = on)
		if (vexRT[Btn7R] == 1)
		{
			SensorValue[lights] = 0;
		}
		//turning light off (1 = off)
		else if (vexRT[Btn8L] == 1)
		{
			SensorValue[lights] = 1;
		}
	}
}
