#include <iostream>
#include "time_span.h"
using namespace std;

int main()
{
	
	TimeSpan dur1(1.334, 90.5), dur2(-45), dur3(45, 67.8, -34), dur4(4, -54, -3);
	TimeSpan dur5(-2, 30.5, 23.7), dur6(6.2, -67, 0), dur7(45, 67.8, -34), dur8(0.5, 30, 5);
	TimeSpan dur10, dur11, dur12;
	dur12 = dur1 + dur3; 
	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	cout << dur3 << endl;
	cout << dur7 << endl;
	cout << dur8 << endl;
	dur10 = dur8 + dur1;
	cout << dur10 << endl;
	dur11 = dur8 - dur3;
	cout << dur11 << endl;
	dur12 += dur2;
	cout << dur12 << endl;

	if (dur3 != dur7)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	} 

	if (dur12 != dur4)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}

} 
