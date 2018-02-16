#pragma config(Sensor, in1,    gyro1,           sensorGyro)
#pragma config(Sensor, in2,    gyro2,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMid,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mobileGoal,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armBase,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armSwing,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           grabber,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightMid,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightFront,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//exact same auton from 11040A

void leftDrive(short speed)
{
	motor[leftFront] = speed;
	motor[leftMid] = speed;
	motor[leftBack] = speed;
}

void rightDrive(short speed)
{
	motor[rightFront] = speed;
	motor[rightMid] = speed;
	motor[rightBack] = speed;
}


void moveForward(short speed) {
	leftDrive(speed);
	rightDrive(speed);
}


task main()
{
	SensorType[in1] = sensorNone;
	wait1Msec(1000);
	SensorType[in1] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;




	//Lower the mobile goal carrier
	motor[mobileGoal] = -127;
	wait1Msec(1000);
	motor[mobileGoal] = 0;

	//Move forward to pick up mobile goal
	while ( (4 * PI * (SensorValue[rightEncoder] / 360) ) < 28 ) {
		moveForward(70);
	}
	moveForward(0);

	//Raise the mobile goal carrier
	motor[mobileGoal] = 127;
	wait1Msec(1500);
	motor[mobileGoal] = 0;

	//Move backward
	while ( (4 * PI * (SensorValue[rightEncoder] / 360) ) > 0 ) {
		moveForward(-50);
	}
	moveForward(0);

	//Turn left by 120 degrees
	while (abs(SensorValue[gyro]) < 1350) {
		rightDrive(50);
		leftDrive(-50);
	}
	rightDrive(0);
	rightDrive(0);

	SensorValue[rightEncoder] = 0;
	//Move forward a little bit
	while ( ( 4 * PI * (SensorValue[rightEncoder] / 360) ) < 10) {
		moveForward(50);
	}
	moveForward(0);

	SensorValue[gyro] = 0;

	//Turn towards 20 point zone
	while (abs(SensorValue[gyro]) < 900) {
		rightDrive(50);
		leftDrive(-50);
	}
	rightDrive(0);
	leftDrive(0);

	//Full speed into 20 Point Zone
	moveForward(100);
	wait1Msec(1500);
	moveForward(0);

	//Lower the mobile goal carrier
	motor[mobileGoal] = -127;
	wait1Msec(3000);
	motor[mobileGoal] = 0;

	//Move backward
	moveForward(-100);
	wait1Msec(1500);
	moveForward(0);
}
