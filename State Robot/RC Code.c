#pragma config(Sensor, in1,    gyro1,           sensorGyro)
#pragma config(Sensor, in2,    gyro2,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMid,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightFront,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mobileGoal,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armBase,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           armSwing,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           grabber,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftFront,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftMid,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftBack,    tmotorVex393_HBridge, openLoop)



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



task main()
{

  short leftSpeed;
  short rightSpeed;
  short
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

    leftDrive(leftSpeed);
    rightDrive(rightSpeed);

    /*				!!!		MOBILE GOAL CARRIER CONTROLS		!!!

    Pressing Button 6U should bring the mobile goal carrier in
    Pressing Button 6D should bring the mobile goal carrier out

      CHANGE VALUES
    When contracted, pot = 2403
    When extended, pot = 348
    */
    if(vexRT[Btn6U] == 1 && SensorValue[armLift] <2403)
    {
      motor[liftArms] = 127;
    }
    else if(vexRT[Btn6D] == 1 && SensorValue[armLift] > 348)
    {
      motor[liftArms] = -127;
    }
    else
    {
      motor[liftArms] = 0;
    }






    if (vexRT[Btn6UXmtr2]==1) {
			armBaseSpeed = -60;
		}
		else if (vexRT[Btn6DXmtr2]==1) {
			armBaseSpeed = 60;
			//grabberSpeed = -30;
		}
		else {
			armBaseSpeed = 0;
		}
		//Controls pinchers movement
		if (vexRT[Btn8UXmtr2]==1)
		{
			grabberSpeed = 127;
		}
		else if (vexRT[Btn8DXmtr2]==1)
		{
			grabberSpeed = -127;
		}
		else {
			grabberSpeed = 0;
		}
		if (vexRT[Btn5UXmtr2]==1) {
			mobileSpeed = 127;
		}
		else if (vexRT[Btn5DXmtr2]==1) {
			mobileSpeed = -127;
		}
		else {
			mobileSpeed = 0;
		}






    //light control (if getting one... VEX inverse the controls... idk y)
    //turning light on (0 = on)
    if (vexRT[Btn7R] == 1)
    {
      SensorValue[lights] = 0;
    }
    //turning light off (1 = off)
    else if (vexRT[Btn8L] == 1)
    {
      SensorValue[lights] = 1;
    }
  }
}
