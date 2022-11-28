#pragma config(Sensor, S3,     light,          sensorLightActive)
// config (dont touch)

task main()
{
	while(true)	{
		while(SensorValue[S3] > 30) {
			motor[motorB] = 50;
			motor[motorC] = 50;
		}
		while(SensorValue[S3] < 30) {
			motor[motorB] = -50;
			motor[motorC] = 50;
		}
	}
}
