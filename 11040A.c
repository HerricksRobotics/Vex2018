#pragma config(Sensor, in1,    armFixed,       sensorPotentiometer)
#pragma config(Sensor, in2,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftArmFix,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmFix,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           mobileGoal,    tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// RC CODE FOR THE VEX ROBOT 11040A

/*NOTE:
might want to use Potentiometer...
		SensorValue(armFixed)
value between 0 and 4095 (mechanical limit the values to between 5 and 4092)
*/

task main()
{
	short leftSpeed;
	short rightSpeed;
	short armBaseCtrl;
	short armLiftCtrl;
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

			Pressing Button 6U should lift entire arm up
			Pressing Button 6D should drag entire arm down
			*/
			armBaseCtrl = (vexRT[Btn6U] << 1) + vexRT[Btn6D];
			switch (armBaseCtrl)
			{
					case 1:
							motor[leftArmFix] = -127;
							motor[rightArmFix] = -127;
							break;
					case 2:
							motor[leftArmFix] = 127;
							motor[rightArmFix] = 127;
							break;
					default:
							motor[leftArmFix] = 0;
							motor[rightArmFix] = 0;
							break;
			}


			/*				!!!		MOVING ARM CONTROLS		!!! *
			// NOTE: use the potentiometers to move the armLifts with the armbase motors
			//For now, there're manual control, but in the future, try to make to automate
			  	it using sensors
					PLANNING NOT TO HAVE MANUAL CONTROL DURING THE COMPETITION!!

			Pressing Button 7U should lift small arm up
			Pressing Button 7D should drag small arm down
			*/
			armLiftCtrl = (vexRT[Btn7U] << 1) + vexRT[Btn7D];
			switch (armLiftCtrl)
			{
				case 1:
						motor[leftLift] = -127;
						motor[rightLift] = -127;
						break;
				case 2:
						motor[leftLift] = 127;
						motor[rightLift] = 127;
						break;
				default:
						motor[leftLift] = 0;
						motor[rightLift] = 0;
						break;
			}



			/*				!!!		GRABBER CONTROLS		!!!

			Pressing Button 8L should open the grabber
			Pressing Button 8R should close the grabber
			*/
			grabberCtrl = (vexRT[Btn8L] << 1) + vexRT[Btn8R];
			switch (grabberCtrl)
			{
					case 1:						//close
							motor[grabber] = -70;
							wait1Msec(250);
							motor[grabber] = 0;
							break;
					case 2:						//open
							motor[grabber] = 70;
							wait1Msec(250);
							motor[grabber] = 0;
							break;
					default:
							motor[grabber] = 0;
							break;
			 }



			/*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

					Pressing Button 8U should bring the mobile goal carrier up
					Pressing Button 8D should bring the mobile goal carrier down
			*/
			mobileGoalCtrl = (vexRT[Btn8D] << 1) + vexRT[Btn8U];
			switch (mobileGoalCtrl)
			{
					case 1:																//Bring carrier up
							motor[mobileGoal] = -127;
							wait1Msec(TIME_DEPLOY_CARRIER * 2);

							//to bring the armLifts down after setting the mobile goal in place
							motor[leftLift] = -127;
							motor[rightLift] = -127;
							wait1Msec(1000);
							motor[leftLift] = 0;
							motor[rightLift] = 0;

							break;
					case 2:																// Bring carrier down
							//to bring the armLifts up to prevent interferance with stacked yellow cones
							motor[leftLift] = 127;
							motor[rightLift] = 127;
							wait1Msec(1000);
							motor[leftLift] = 0;
							motor[rightLift] = 0;

							motor[mobileGoal] = 127;
							wait1Msec(TIME_DEPLOY_CARRIER);
							break;
					default:
							motor[mobileGoal] = 0;
							break;
			}
	}

}
