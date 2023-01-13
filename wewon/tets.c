/*
Script by Mason Varey and Anthony Seyler
Started on 2022-12-16
*/

#pragma config(Sensor, S1,     ,               sensorTouch)
#pragma config(Sensor, S2,     ,               sensorTemperature)
#pragma config(Sensor, S3,     ,               sensorLightActive)
#pragma config(Sensor, S4,     ,               sensorSONAR)

int Temperature;
int x;

void turn(char* direction, int speed, int del, char* material){
	if (direction == "r"){
		motor[motorB] = -speed;
		motor[motorC] = speed;
	}
	else if (direction == "l"){
		motor[motorB] = speed;
		motor[motorC] = -speed;
	}

	if (material == "mat") {
		delay(del * 3.8); // placeholder
	}
	else if (material == "table") {
		delay(del * 3.55);
	}
	else if (material == "wood") {
		delay(del * 4); // placeholder
	}
	motor[motorB] = 0;
	motor[motorC] = 0;
	delay(200);
}

void flamboyantwater() {
  motor[motorC] = 0;
  motor[motorB] = 0;
  motor[motorA] = 20;
  delay(400);
  motor[motorA] = 0;
  while(x < 20){
    Temperature = SensorValue[S4];
    displayTextLine(3, "temp=%d", Temperature);
    delay(500);
    x++;
  }
  motor[motorA] = -20;
  delay(400);
}

task main(){
  while (SensorValue[S4] > 40){ // while sonar above 40
    motor[motorC] = 50;
    motor[motorB] = 50;
  }
  turn("r", 50, 45, "table");
  flamboyantwater();
  turn("l", 50, 45, "table");
  motor[motorC] = 0;
  motor[motorB] = 0;
  turn("r", 50, 200, "table");
  while (SensorValue[S3] > 45){
    motor[motorC] = 50;
    motor[motorB] = 50;
    displayTextLine(2, "light=%d", SensorValue[S3]);
  }
}
