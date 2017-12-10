#pragma config(Sensor, in3,    gryo,           sensorGyro)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
//based of 2-motor drive

//This class is purely for calculating the robot's position relative to the playing area


/*
Change in X = COS(Radian) * Distance
Change in Y = SIN(Radian)* Distance
and
Y += Change in Y
X += Change in X

this will get the basics of how the code works, just keep in mind the SIN and COS functions want radians,
and they output Radians, but the gyro outputs in degrees, so you will have to use the function RadiansToDegrees(angle)
then you put that into the SIN and COS functions

once you have this, you can track your robots location, from there it is just making the auto-navigation code,
and fine-tuning every thing

for autonavigation, you just need a control loop to turn you to a specific location on the Gyro Sensor,
and you use the ArcTan function of robotC
*/

int leftEncoderValue = 0;
int rightEncoderValue = 0;
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
    /*
    changeInX = cos(z) * distance;
    changeInY = sin(z) * distance;

    idk how to calculate the distance using 2 encoders currently...
    */
    x += changeInX;
    y += changeInY;
}






//calculating the distance from the starting position
float distance()
{
  float distance = sqrt(ChangeInX^2+ChangeInY^2);

  return distance;
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
