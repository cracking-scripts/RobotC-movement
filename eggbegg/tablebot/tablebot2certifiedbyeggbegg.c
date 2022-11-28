#pragma config(Sensor, S3,     light,          sensorLightActive)
// config (dont touch)

int timedelay = 0;
int bump = 0;
char timedelays[5];
char bumps[5];

int randy(int min, int max){
   return min + rand() / (32767 / (max - min + 1) + 1);
}

void turn() {
	motor[motorB] = -50;
	motor[motorC] = 50;
	delay(randy(200, 2000);
}

void back() {
	motor[motorB] = -50;
	motor[motorC] = -50;
	delay(300);
}

task main() {
	while(true)	{
		timedelay = 0
		displayTextLine(2, "bump count");
		sprintf(bumps, "%d", bump);
		displayTextLine(3, bumps);
		while(SensorValue[S3] > 30) {
			motor[motorB] = 50;
			motor[motorC] = 50;
			displayTextLine(0, "time per bump");
			timedelay ++
			sprintf(timedelays, "%d", timedelay);
			displayTextLine(1, timedelays);
		}
		bump ++
		displayTextLine(2, "bump count");
		sprintf(bumps, "%d", bump);
		displayTextLine(3, bumps);
		back()
		turn()
	}
}
