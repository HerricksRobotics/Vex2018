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


//15sec AUTON!!!!!!! (Standard)

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

//returns in Inchs
float leftDistance()
{
	return 4 * PI * (SensorValue[leftEncoder]/360);
}

//returns in Inches
float rightDistance()
{
	return 4 * PI * (SensorValue[rightEncoder]/360);
}


task main()
{

  short speed = 100;          //change if needed
  float distance = 100.752;   //in inches

  //starting on the right side (w/o preload placement) and facing at the mobile goal

  SensorType[in2] = sensorNone;
	wait1Msec(1000);
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;


  while(abs(SensorValue[gyro]) < 250) //35.4253 degrees to be exact
  {
    //depending what side robot is desired to be places
    rightDrive(speed);
    //leftDrive(speed);
  }
  rightDrive(0);



  //Moving Foward to block the opposite robot from getting its mobile goal
  while (rightDistance() < distance || leftDistance() < distance)
  {
    if (SensorValue[rightEncoder] > SensorValue[leftEncoder])
    {
      leftDrive(speed);
      rightDrive(0);
    }
    else
    {
      rightDrive(speed);
      leftDrive(0);
    }
  }


  leftDrive(0);
  rightDrive(0);
}
