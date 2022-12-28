#pragma once

#include <iostream>;

class TimeSpan
{
public:
	TimeSpan();

	TimeSpan(int sec);

	TimeSpan(int min, int sec);

	TimeSpan(int hours, int min, int sec);

	int hours() const; //return the number of hours as an int

	int minutes() const; //return the number of minutes as an int
	
	int seconds() const; //return the number of Seconds as an int

};