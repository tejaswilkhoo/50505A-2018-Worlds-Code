#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potentiometerbar, sensorPotentiometer)
#pragma config(Sensor, in8,    potentiometerlift, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  ,               sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftdrive,     tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           leftdrive,     tmotorVex393HighSpeed_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port4,           chainbar,      tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port5,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           conelift,      tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port8,           mobilelift,    tmotorVex393_MC29, PIDControl, encoderPort, dgtl1)
#pragma config(Motor,  port9,           rightdrive,    tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port10,          rightdrive,    tmotorVex393HighSpeed_HBridge, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	motor[port5] = 20;

	repeatUntil(SensorValue(in1) >= 3000)
	{
		motor[port4] = -63;
	}
	motor[port4] = 20;
	wait1Msec(100);

	repeatUntil(SensorValue(in8) >= 3400)
	{
		motor[port7] = 63;
	}
	motor[port7] = 0;
	motor[port4] = 0;
	wait1Msec(100);

	motor[port1] = 63;
	motor[port2]  = 63;
	motor[port9] = 63;
	motor[port10]  = 63;
	wait1Msec(800);

	motor[port1] = 0;
	motor[port2] = 0;
	motor[port9] = 0;
	motor[port10] =0;
	sleep(1000);

	repeatUntil(SensorValue(in8) <= 3350)
	{
		motor[port7] = -63;
	}
	motor[port7] = 0;


	motor[port5]=-127;
	wait1Msec(500);

	repeatUntil(SensorValue(in8) >= 3500)
	{
		motor[port7] = 63;
	}
	motor[port7] = 0;

	motor[port1] = -63;
	motor[port2]  = -63;
	motor[port9] = -63;
	motor[port10]  = -63;
	wait1Msec(700);


}
