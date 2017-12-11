#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
//based of 2-motor drive

//This class is purely for calculating the robot's position relative to the playing area


int leftEncoderValue = 0;
int rightEncoderValue = 0;
float leftDistance;
float rightDistance;
float changeInX;
float changeInY;
float x = 0;                  //the x position from the starting position
float y = 0;                  //the y position from the starting position
float z = 0;                  //degrees of the robot facing from the starting position


//(x,y) of the robot's current position
void location()
{
    z = degreesToRadians(sensorValue[gyro]);              //gyro outputs degrees... gotta change it to rad
                                                        //bc sin and cos outputs rad :/

    leftDistance = 4 * PI * ((leftEncoderValue)/360);
    rightDistance = 4 * PI * ((rightEncoderValue)/360);

    /*
    distance = something..... god dam centripetal forces and math :(
    changeInX = cos(z) * distance;
    changeInY = sin(z) * distance;
    */

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


//calculating the quickest distance to the target location and getting there
void targetLocation()
{

}


void gps()
{

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
    /*				!!!		DRIVE CONTROLS		!!!        */
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

    leftEncoderValue = SensorValue[leftEncoder];
    rightEncoderValue = SensorValue[rightEncoder];

    gps();
  }
}
