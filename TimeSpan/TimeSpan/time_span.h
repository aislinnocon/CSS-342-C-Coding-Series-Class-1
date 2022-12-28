#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <string>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;


// casting of a constructor follows regular java casting rules
// generally want cosntructor to intitalize object/variables
// 1. can use intializor list 2. when it gets called


class TimeSpan
{
public:
	// Constructors
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds); 

	// Getters-setters
	int hours() const; 
	int minutes() const; 
	int seconds() const;
	void set_time(int hours, int minutes, int seconds); 

	// Actions
	void round_seconds(); 
	void reallocate_minutes();
	void reallocate_hours(); 
	double next_unit(double &a, double &b);
	double negative(double &a, double &b); 

	// Overload operators
	friend ostream& operator<<(ostream& stream, const TimeSpan& time_span);
	TimeSpan operator-(const TimeSpan& time_span) const; 
	TimeSpan& operator-=(const TimeSpan& time_span);
	TimeSpan operator+(const TimeSpan& time_span) const; 
	TimeSpan& operator+=(const TimeSpan& time_span);
	bool operator==(const TimeSpan& time_span) const;
	bool operator!=(const TimeSpan& time_span) const;
	bool operator<(const TimeSpan& time_span) const;
	bool operator<=(const TimeSpan& time_span) const;
	bool operator>(const TimeSpan& time_span) const;
	bool operator>=(const TimeSpan& time_span) const;

private:
	double seconds_;
	double minutes_;
	double hours_;

};
#endif