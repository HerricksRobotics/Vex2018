#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    gyro2,          sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  touchSensor,    sensorTouch)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightMid,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           mobileLift,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           elevatorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           swingArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           grabber,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           leftMid,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rightFront,    tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveForward(int speed) {
	motor[leftBack] = speed;
	motor[leftMid] = speed;
	motor[leftFront] = speed;
	motor[rightBack] = speed;
	motor[rightMid] = speed;
	motor[rightFront] = speed;
}

void turnRight(int speed) {
	motor[leftBack] = speed;
	motor[leftMid] = speed;
	motor[leftFront] = speed;
	motor[rightBack] = -speed;
	motor[rightMid] = -speed;
	motor[rightFront] = -speed;
}

void turnLeft(int speed) {
	motor[rightBack] = speed;
	motor[rightMid] = speed;
	motor[rightFront] = speed;
	motor[leftBack] = -speed;
	motor[leftMid] = -speed;
	motor[leftFront] = -speed;
}

task main()
{
	SensorValue[rightEncoder] = 0;
	SensorType[in1] = sensorNone;
	SensorType[in2] = sensorNone;
	wait1Msec(1000);
	SensorType[in1] = sensorGyro;
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);

	//Roll grabber down
	motor[grabber] = 127;

	//Raise the elevator lift
	motor[elevatorLift] = -127;
	wait1Msec(1000);
	motor[elevatorLift] = 0;

	//Lower the mobile goal lift
	motor[mobileLift] = 127;
	wait1Msec(2000);
	motor[mobileLift] = 0;

	//Move Forward
	while (4 * PI * SensorValue[rightEncoder] / 360 < 48) {
		moveForward(127);
	}
	moveForward(0);

	//Raise the mobile goal lift
	motor[mobileLift] = -127;
	wait1Msec(2000);
	motor[mobileLift] = 0;

	//Lower the elevator lift
	motor[elevatorLift] = 127;
	wait1Msec(1000);
	motor[elevatorLift] = 0;

	//Turn the grabber off
	motor[grabber] = 0;

	//Move Backward
	while(4 * PI * SensorValue[rightEncoder] / 360 > 0) {
		moveForward(-127);
	}
	moveForward(0);

	//Turn Left
	while( abs( SensorValue[gyro] ) < 1225) {
		turnLeft(127);
	}
	turnLeft(0);

	//Reset the rightEncoder
	SensorValue[rightEncoder] = 0;

	//Move Forward
	while (4 * PI * SensorValue[rightEncoder] / 360 < 12) {
		moveForward(127);
	}
	moveForward(0);

	//Reset the gyro
	SensorValue[gyro] = 0;

	//Turn Left 90 Degrees
	while ( abs( SensorValue[gyro]) < 800) {
		turnLeft(127);
	}
	turnLeft(0);

	//Raise the elevator lift
	motor[elevatorLift] = -127;
	wait1Msec(1000);
	motor[elevatorLift] = 0;

	//Move Forward at full speed
	moveForward(127);
	wait1Msec(1500);
	moveForward(0);

	//Lower the mobile goal lift
	motor[mobileLift] = 127;
	wait1Msec(1000);
	motor[mobileLift] = 0;

	//Move backward at full speed
	moveForward(-127);
	wait1Msec(2000);
	moveForward(0);

}
