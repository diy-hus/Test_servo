#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>

#include <pigpio.h>

using namespace std;

int run = 1;

void stop(int signum)
{
   run = 0;
}


int main()
{
	if (gpioInitialise() < 0) return -1;
	gpioSetSignalFunc(SIGINT, stop);

	int servo, value;
	
	while (run)
	{
		cin >> servo >> value;
		gpioServo(servo, value);
	}
	
	gpioTerminate();
	
	return 0;
}
