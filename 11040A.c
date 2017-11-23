#pragma config(Sensor, in1,    rotatingArmAngle,       sensorPotentiometer)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftArmFix,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmFix,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           mobileGoal,    tmotorVex393_MC29, openLoop, reversed)

// TEST CODE FOR THE VEX ROBOT 11040A

/*NOTE:
		SensorValue(rotatingArmAngle)
value between 0 and 4095 (mechanical limit the values to between 5 and 4092)
*/

task main()
{
	int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int grabberSpeed;
	//bool ifMobileGoalActivated = false;

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



			//ARM CONTROLS
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

			// NOTE: use the potentiometer to move the armLifts with the armbase motors
			/*  !!!NOT YET PRESENT ON THE ROBOT!!!
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
			motor[grabber] = grabberSpeed;
			*/


			//To bring down the mobile goal carrier
			if (vexRT[Btn8D] == 1)
			{
				//ifMobileGoalActivated = true;
				motor[mobileGoal] = -127;
			}
			else
			{
				motor[mobileGoal] = 0;
			}


			//To bring up the mobile goal carrier
			if (vexRT[Btn8U] == 1)
			{
				//ifMobileGoalActivated = true;
				motor[mobileGoal] = -127;
			}
			else
			{
				motor[mobileGoal] = 0;
			}




		/*  trash...might delete soon
		//when Btn8D is pressed
		while (ifMobileGoalActivated)
		{
			motor[leftArmFix] = -127;									//setting arms down to the ground
			motor[rightArmFix] = -127;
			wait1Msec(1000);				//adjust this value

			motor[mobileGoal] = -127;									//setting the carrier down
			wait1Msec(1000);				//adjust this value


			//ARM CONTROLS
			if (vexRT[Btn6U] == 1)
			{
				armBaseSpeed = 127;
			}

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


			//Disactivating the mobile goal carrier using Button 8U
			//also reactivating the arm
			if (vexRT[Btn8U] == 1)
			{
				motor[mobileGoal] = 127;							//change value to adjust putting up the carrier
				wait1Msec(1000);
				ifMobileGoalActivated = false;
			}

		}
		*/


	}

}
