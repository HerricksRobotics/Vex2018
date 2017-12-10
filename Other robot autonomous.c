#pragma config(Sensor, in1,    fixedArm,       sensorPotentiometer)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftArmFix,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmFix,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           mobileGoal,    tmotorVex393_MC29, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void armUp(int speed)

	{
		motor[leftArmFix] = speed;
		motor[leftLift] = speed;
		motor[rightArmFix] = speed;
		motor[rightLift] = speed;
		}

void armDown(int speed)
	{
		motor[leftArmFix] = -speed;
		motor[leftLift] = -speed;
		motor[rightArmFix] = -speed;
		motor[rightLift] = -speed;
	}

void pinchOpen(int speed)
	{
		motor[grabber] = -speed;
	}
	
void pinchClose(int speed) 
	{
  	motor[grabber] = speed;
	}
task main()
{
	int armSpeed = 60;
	int wheelSpeed = 100;
	int pincherSpeed = 30;
	int TIME = 5; //in seconds
	while(true)
	{
		//pinchOpen(pincherSpeed);
		//Cone in hand, move forward
		motor[leftDrive] = wheelSpeed;
		motor[rightDrive] = wheelSpeed;
		wait1Msec(TIME * 1000);
		
		//Open Pincher to drop Yellow Cone on Red/Blue Cone
		pinchOpen(pincherSpeed);
		
		//Picked up Stacked Cones
		armDown(armSpeed);
		pinchClose(pincherSpeed);
		armUp(armSpeed);
		//Turn the other way
		motor[leftDrive] = wheelSpeed;
		wait1Msec(TIME*1000);
		//Move forward to base
		motor[leftDrive] = wheelSpeed;
		motor[rightDrive] = wheelSpeed;
		wait1Msec(TIME * 1000);
		//Place stacked cones in base
		armDown(pincherSpeed);
		pinchOpen(pincherSpeed);
		armUp(pincherSpeed);
		pinchClose(pincherSpeed);
	}
}