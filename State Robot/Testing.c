#pragma config(Sensor, in1,    pot,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, in3,    lineFollower,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  Encoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl4,  sonarSensor,         sensorSONAR_cm)
#pragma config(Motor,  port1,           port1Motor,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port5,           port5Motor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          port10Motor,     tmotorVex393_HBridge, openLoop, reversed)



task main()
{
  SensorType[in2] = sensorNone;
	wait1Msec(1000);
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);
	SensorValue[gyro] = 0; //positive counterclockwise

	SensorValue[Encoder] = 0;


  while (true)
  {
    motor[port1Motor] = 127;
    motor[port5Motor] = 127;
    motor[port10Motor] = 127;
    wait1Msec(5000);
    motor[port1Motor] = -127;
    motor[port5Motor] = -127;
    motor[port10Motor] = -127;
  }





}
