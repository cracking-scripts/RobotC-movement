#pragma config(Sensor, S3,     light,          sensorLightActive)

int lightval;

void move() {
	motor[motorB] = 100;
	motor[motorC] = 100;
}
	
void action() {
	while (true) {
		lightval = SensorValue[S3];
		if (lightval > 35) {
			motor[motorB] = -40;
			motor[motorC] = 100;
		}
		else {
			motor[motorB] = 100;
			motor[motorC] = -40;
		}
		move();
	}
}

// robot function
task main() {
	action();
}
