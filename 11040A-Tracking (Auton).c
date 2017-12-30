#pragma config(Sensor, in1,    armLift,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           rightFront,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port3,           rightMid,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           liftArms,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftBBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftMid,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftFront,     tmotorVex393_HBridge, openLoop, reversed)

//This class is purely for calculating the robot's position relative to the playing area


float leftDistance;
float rightDistance;
float changeInX;
float changeInY;
float x = 0;                  //the x position from the starting position
float y = 0;                  //the y position from the starting position
float z = 0;                  //radians of the robot facing from the starting position
                              //LOL WHEN RICHARD FINDS THIS SHIT IT MEANS HES RETARDED

//(x,y) of the robot's current position
void location()
{
    float radius;
    float totalDistance;

    z = degreesToRadians(sensorValue[gyro]);              //gyro outputs degrees... gotta change it to rad



    leftDistance = 4 * PI * (sensorValue[leftEncoder]/360);
    rightDistance = 4 * PI * (sensorValue[rightEncoder]/360);


    if (leftDistance < rightDistance)
    {
      radius = (leftDistance/z - rightDistance/z)/2 + leftDistance/z
      totalDistance = radius * z;
    }
    else
    {
      radius = (rightDistance/z - leftDistance/z)/2 + rightDistance/z
      totalDistance = radius * z;
    }

    changeInX = totalDistance * cos(z);
    changeInY = totalDistance * sin(z);

    x += changeInX;
    y += changeInY;
}



//calculating the distance from the starting position
float distance()
{
  return sqrt(pow(changeInX,2) + pow(changeInY,2);
}



float angle()
{
  float angle = atan(ChangeInY/ChangeInX);
  return angle;
}



//calculating the quickest distance to the target location and movoing there
void targetLocation()
{

}




/*
      THE MAIN BRAINS
*/
void gps()
{

}



//***************************************************************************************************************
//Movements for Robot


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



//Arm Controls with Drive Controls
//CHANGE BC THIS IS SLOW AF
void extendArm(short leftSpeed, short rightSpeed)
{
  if (SensorValue[armLift] > 465)
  {
    motor[liftArms] = 127;
  }
  else
  {
    motor[liftArms] = 0;
    leftDrive(leftSpeed);
    rightDrive(rightSpeed);
  }
}

void contractArm(short leftSpeed, short rightSpeed)
{
  if (SensorValue[armLift] < 2110)
  {
    motor[liftArms] = -127;
  }
  else
  {
    motor[liftArms] = 0;
    leftDrive(leftSpeed);
    rightDrive(rightSpeed);
  }

}


task main()
{
  //First, have to recalibrate Gyro
  SensorType[in3] = sensorNone;
	wait1Msec(1000);
	SensorType[in3] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise

  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;

  short leftSpeed;
  short rightSpeed;


  while(true)
  {
    /*				!!!		DRIVE CONTROLS		!!!
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
    */



    gps();
  }
}
