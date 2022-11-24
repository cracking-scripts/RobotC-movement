#pragma config(Sensor, S3,     light,          sensorLightActive)

void move() {
	motor[motorB] = 70;
	motor[motorC] = 70;
}

void onturn() {
	motor[motorB] = -70;
	motor[motorC] = 70;
	delay(435);
}

void action() {
	while (true) {
		int lightval = SensorValue[S3];
		move();
		if (lightval < 35) {
			delay(1000);
			onturn();
		}
	}
}

task main()
{
	action();
}
