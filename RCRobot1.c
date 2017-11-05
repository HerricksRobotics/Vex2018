#pragma config(Sensor, in1,    fixedArm,       sensorPotentiometer)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftArmFix,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmFix,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           mobileGoal,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
!!!IMPORTANT MESSAGE!!!		DO NOT TOUCH THIS FILE

RC CODE FOR THE VEX ROBOT 11040A
*/


task main()
{
	int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int grabberSpeed;
	bool ifMobileGoalActivated = false;

	while(true)
	{
		//DRIVE CONTROLS
		//To control the left side using channel 3
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch3];
		}

		//ARM CONTROLS
		//To control the right side using channel 2
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch2];
		}

		motor[leftDrive] = leftSpeed;
		motor[rightDrive] = rightSpeed;


		//lift up yeloow cones using Button 6U
			if (vexRT[Btn6U] == 1)
			{
				armBaseSpeed = 127;
			}
			//lift down yeloow cones using Button 6D
			else if (vexRT[Btn6D] == 1)
			{
				armBaseSpeed = -127;
			}
			else
			{
				armBaseSpeed = 0;
			}

			motor[leftArmFix] = armBaseSpeed;
			motor[rightArmFix] = armBaseSpeed;



		//For now, the motors needed for this function aren't attached...
		/*Activating the mobile goal carrier up using Button 8D
		also disabling the movement of the arm for stablity
		if (vexRT[Btn8D] == 1)
		{
			ifMobileGoalActivated = true;
		}


		while (!ifMobileGoalActivated)
		{
			//lift up yeloow cones using Button 6U
			if (vexRT[Btn6U] == 1)
			{
				armBaseSpeed = 127;
			}
			//lift down yeloow cones using Button 6D
			else if (vexRT[Btn6D] == 1)
			{
				armBaseSpeed = -127;
			}
			else
			{
				armBaseSpeed = 0;
			}

			motor[leftArmFix] = armBaseSpeed;
			motor[rightArmFix] = armBaseSpeed;

			//opening graber using Botton 5U
			if (vexRT[Btn5U] == 1)
			{
				grabberSpeed = 127;
			}
			else if (vexRT[Btn5D] == 1)
			{
				grabberSpeed = -127;
			}
			else
			{
				grabberSpeed = 0;
			}
			//motor[grabber] = grabberSpeed;

		}
		if (ifMobileGoalActivated)
		{
			//deploy mobile goal carrier down and move arms up to lift mobile goal cones
			if (vexRT[Btn8R] == 1)
			{
				ifMobileGoalActivated = false;
				//move set arms to bottom and mobile goal carrier motors back up, respectfully
			}

		}
		*/

	}

}