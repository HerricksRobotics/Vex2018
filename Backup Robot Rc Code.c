#pragma config(Motor,  port1,           leftDrive,     tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           rightDrive,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           leftArmFix,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           rightArmFix,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           leftLiftT,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           leftLiftB,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           rightLiftT,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           rightLiftB,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           grabber,       tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int leftSpeed;
	int rightSpeed;
	int fixArmBaseSpeed;
	int liftArmBaseSpeed;
	int grabberSpeed;
	bool ifMobileGoalActivated = false;

	while(true)
	{
		//Control Right Side Wheels
		if (vexRT[Ch2] > -35 && vexRT[Ch2] < 35)
			{
				rightSpeed = 0;
			}
		else
			{
				rightSpeed = vexRT[Ch2];
			}

		//Control Left Side Wheels
		if (vexRT[Ch3] > -35 && vexRT[Ch3] < 35)
			{
				leftSpeed = 0;
			}
		else
			{
				leftSpeed = vexRT[Ch3];
			}
		
		//Controls Larger Arms Movement 
		if (Btn6U==1) //Button 6U raises the larger arms
			{
				liftArmBaseSpeed = 80;
			}
		else if (Btn6D==1) //Button 6D lowers the larger arms
			{
				liftArmBaseSpeed = -80;
			}
		else
			{
				liftArmBaseSpeed = 0;
			}
		
		//Controls Smaller Arms Movement
		if (Btn5U==1) //Button 6U lowers the smaller arms
			{
				fixArmBaseSpeed = 40;
			}
		else if (Btn5D==1) //Button 6D lowers the smaller arms
			{
				fixArmBaseSpeed = 40;
			}
		else
			{
				fixArmBaseSpeed = 0;
			}
		
		//Controls Grabbers
		if (Btn7U==1) //Opens the pinches
			{
				grabberSpeed = 30;
			}
		else if (Btn8U==1) //Closes the pinchers
			{
				grabberSpeed = 30;
			}
		else
			{
				grabberSpeed = 0;
			}
		
		motor[leftDrive] = leftSpeed;
		motor[rightDrive] = rightSpeed;
		motor[leftLiftT] = liftArmBaseSpeed;
		motor[leftLiftB] = liftArmBaseSpeed;
		motor[rightLiftT] = liftArmBaseSpeed;
		motor[rightLiftB] = liftArmBaseSpeed;
		motor[leftArmFix] = fixArmBaseSpeed;
		motor[rightArmFix] = fixArmBaseSpeed;
		motor[grabber] = grabberSpeed;
	}
}
		
			
			