//credit to TheXbots on Github
//Put this before the task main()

void DoAction(char* dirorstraight, int length, int speed, bool useangle)
{
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
	
	if (useangle == true) {
		delay((4.04 * length/speed) * length);
	}
	
	else if (useangle == false) {
		delay(length);
	}
}
