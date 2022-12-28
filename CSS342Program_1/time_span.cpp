#include <iostream>; 
#include "vending_bank.h"

//Designand implement a TimeSpan class which represents a duration of time in hours, minutes,
//and seconds.The order hours, minutes, and seconds should be respected in the constructor.
//As an example
//TimeSpan duration(1, 2, 3);
//is a duration of time of 1 hour, 2 minutes and 3 seconds.
//In the instances of the TimeSpan class you should store the values as integers in a normalized
//way.The number of seconds should be between - 60 and 60 when stored; number of minutes
//should be between - 60 and 60 when stored.That is, a user can create a TimeSpan object of 90
//seconds but it should be stored as 1 minute, 30 seconds.
//You do not need to worry about integer overflow for very big TimeSpan objects.
//Accessor functions required
//The TimeSpan class should implement the following member functions :
// 

#include "time_span.h"


TimeSpan::TimeSpan()
{
	
};


//int hours() const; return the number of hours as an int
//int minutes() const; return the number of minutes as an int
//int seconds() const: return the number of Seconds as an int
//void set_time(int hours, int minutes, int seconds) :