#pragma config(Sensor, in1,    gyro,       sensorPotentiometer)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftArmFix,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmFix,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           mobileGoal,    tmotorVex393_MC29, openLoop, reversed)

// RC CODE FOR THE VEX ROBOT 11040A

/*NOTE:
		SensorValue(gyro)
value between 0 and 4095 (mechanical limit the values to between 5 and 4092)
*/

task main()
{
	short leftSpeed;
	short rightSpeed;
	short armBaseSpeed;
	const short TIME_DEPLOY_CARRIER = 500;						//time to make a 90 deg angle for the mobile goal carrier
	short grabberCtrl;
	short mobileGoalCtrl;

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

			motor[leftDrive] = leftSpeed;
			motor[rightDrive] = rightSpeed;



			/*				!!!		BASE ARM CONTROLS		!!!
			*/
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



			/*				!!!		MOVING ARM CONTROLS		!!! */
			// NOTE: use the potentiometer to move the armLifts with the armbase motors
			/*  !!!NOT YET PRESENT ON THE ROBOT!!!



			/*				!!!		GRABBER CONTROLS		!!!

			Pressing Button 8L should open the grabber
			Pressing Button 8R should close the grabber
			*
			grabberCtrl = (vexRT[Btn8L] << 1) + vexRT[Btn8R];
			switch (grabberCtrl)
			 	{
					case 1:
							motor[grabber] = -127;
							wait1Msec(1000);
							motor[grabber] = 0;
							break;
					case 2:
							motor[grabber] = 127;
							wait1Msec(1000);
							motor[grabber] = 0;
							break;
					default:
							motor[grabber] = 0;
							break;
			 }*/



			/*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

					Pressing Button 8U should bring the mobile goal carrier up
						*Note, the grabber will get in the way if mobile goal contains lots of yellow cones,
							code the 2 arm motors to bring them up or have the grabber grab one of the cones for stability

					Pressing Button 8D should bring the mobile goal carrier down
			*/
			mobileGoalCtrl = (vexRT[Btn8D] << 1) + vexRT[Btn8U];
			switch (mobileGoalCtrl)
			 {
					case 1:
							motor[mobileGoal] = -127;
							wait1Msec(TIME_DEPLOY_CARRIER);
							break;
					case 2:
							motor[mobileGoal] = 127;
							wait1Msec(TIME_DEPLOY_CARRIER);
							break;
					default:
							motor[mobileGoal] = 0;
							break;
			 }
	}

}
