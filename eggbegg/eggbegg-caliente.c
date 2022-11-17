// hard stop - vulnerable to movement offset, but fast
void hardStop(int length) {
	motor(motorB) = 0;
	motor(motorC) = 0;
	delay(length)

// smooth stop - to combat movement offset
void smoothStop(int length, int initialspeed) {
	motor(motorB) = initialspeed / 2;
	motor(motorC) = initialspeed / 2;
	delay(length / 2);
	motor(motorB) = 0;
	motor(motorC) = 0;
	delay(length / 2);

void doAction(char* direction, int length, int speed, bool useAngle, bool useSmooth) {
	// specify direction and execute
	if (dirorstraight	== "Straight") {
		motor(motorB) = speed;
		motor(motorC) = speed;
	}
	else if (dirorstraight == "Left") {
		motor(motorB) = speed;
		motor(motorC) = -speed;
	}
	else if (dirorstraight == "Right") {
		motor(motorB) = -speed;
		motor(motorC) = speed;
	}
	else if (dirorstraight == "Back") {
		motor(motorB) = -speed;
		motor(motorC) = -speed;
	}
	
	// toggle between angle and length
	if (useAngle == true) {
		delay(7.1462476767676 * length);
	}
	else if (useangle == false) {
		if (useSmooth == true) {
			smoothStop(length);
		}
		else if (useSmooth == false) {
			hardStop(length);
		}
	}
}

task main() {
	
}
