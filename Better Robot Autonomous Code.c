#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    Potentiometer,  sensorPotentiometer)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightArmT,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           leftArmT,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           frontMotor,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           rightArmB,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           leftArmB,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          bigArm,        tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void armUp(int speed)
	{
		motor[leftArmT] = speed;
		motor[leftArmB] = speed;
		motor[rightArmT] = speed;
		motor[rightArmB] = speed;
	}

void armDown(int speed)
	{
		motor[leftArmT] = -speed;
		motor[leftArmB] = -speed;
		motor[rightArmT] = -speed;
		motor[rightArmB] = -speed;
	}

void pinchOpen(int speed)
	{
		motor[frontMotor] = -speed;
	}

void pinchClose(int speed)
	{
		motor[frontMotor] = speed;
	}

void armLift (int bigSpeed)
	{
		motor[bigArm] = bigSpeed;
	}

void right_Turn(int degrees10) {
	while(abs(SensorValue[in8]) < degrees10)
 	{
 		//...continue turning
	 	motor[rightFront] = 25;
	 	motor[rightBack] = 25;
 		motor[leftFront] = -25;
 		motor[leftBack] = -25;
 	}
}
void right_Turn(int degrees10) {
	while(abs(SensorValue[in1]) < degrees10)
 	{
 		//...continue turning
	 	motor[leftFront] = 25;
	 	motor[leftBack] = 25;
 		motor[rightFront] = -25;
 		motor[rightBack] = -25;
 	}
}

void liftArm(int liftAngle)
{
	motor[leftArmB] = 127;
	motor[leftArmT] = 127;
	motor[rightArmB] = 127;
	motor[rightArmT] = 127;
	SensorValue(Potentiometer);
	motor[leftArmB] = 0;
	motor[leftArmT] = 0;
	motor[rightArmB] = 0;
	motor[rightArmT] = 0;
}

void moveForward(int speed, int time) {
		motor[leftFront] = speed;
		motor[leftBack] = speed;
		motor[rightFront] = speed;
		motor[rightBack] = speed;
		wait1Msec(time * 1000);
		motor[leftFront] = 0;
		motor[leftBack] = 0;
		motor[rightFront] = 0;
		motor[rightBack] = 0;
}


task main()
{

	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
 	SensorType[in1] = sensorNone;
 	wait1Msec(1000);
 	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
 	SensorType[in1] = sensorGyro;
	wait1Msec(2000);
	int armSpeed = 60;
	int wheelSpeed = 100;
	int pincherSpeed = 30;
	int bigSpeed = 200;
	int TIME = 5; //in seconds
	//pinchOpen(pincherSpeed);
	//Cone in hand, move forward
	moveForward(127, 10);
		
	/*
		//Open Pincher to drop Yellow Cone on Red/Blue Cone
		pinchOpen(pincherSpeed);

		//Picked up Stacked Cones
		armDown(armSpeed);
		pinchClose(pincherSpeed);
		armUp(armSpeed);

		//Turn the other way
		motor[leftFront] = wheelSpeed;
		motor[leftBack] = wheelSpeed;
		wait1Msec(TIME*1000);

		//Move forward to base
		motor[leftFront] = wheelSpeed;
		motor[leftBack] = wheelSpeed;
		motor[rightFront] = wheelSpeed;
		motor[rightBack] = wheelSpeed;
		wait1Msec(TIME * 1000);

		//Place stacked cones in base
		armDown(pincherSpeed);
		pinchOpen(pincherSpeed);
		armUp(pincherSpeed);
		pinchClose(pincherSpeed);*/
}
