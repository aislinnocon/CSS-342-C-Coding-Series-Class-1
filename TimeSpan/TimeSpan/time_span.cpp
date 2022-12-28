#include "time_span.h"

TimeSpan::TimeSpan()
{
}

TimeSpan::TimeSpan(double seconds) : hours_(0), minutes_(0), seconds_(seconds)
{
	if (seconds >= 0)
	{
		round_seconds();
		next_unit(seconds_, minutes_);
	}
	else
	{
		round_seconds();
		negative(seconds_, minutes_);
		next_unit(seconds_, minutes_);
	}
}


TimeSpan::TimeSpan(double minutes, double seconds) : hours_(0), minutes_(minutes), seconds_(seconds)
{
	if (minutes >= 0 && seconds >= 0)
	{
		reallocate_minutes();
		round_seconds();
		next_unit(seconds_, minutes_);
		next_unit(minutes_, hours_);
	} 
	else
	{
		reallocate_minutes();
		round_seconds();
		next_unit(minutes_, hours_);
		negative(seconds_, minutes_);
		next_unit(seconds_, minutes_);
	}
}


TimeSpan::TimeSpan(double hours, double minutes, double seconds) : hours_(hours), minutes_(minutes), seconds_(seconds)
{
	if (hours >= 0 && minutes >= 0 && seconds >= 0)
	{
		reallocate_hours();
		reallocate_minutes();
		round_seconds();
		next_unit(seconds_, minutes_);
		next_unit(minutes_, hours_);
	}
	else
	{
		reallocate_hours();
		reallocate_minutes();
		round_seconds();
		next_unit(minutes_, hours_);
		negative(minutes_, hours_);
		next_unit(seconds_, minutes_);
		negative(seconds_, minutes_);
	} 
}


int TimeSpan::hours() const
{
	return static_cast<int>(hours_);
}

int TimeSpan::minutes() const
{
	return static_cast<int>(minutes_);
}

int TimeSpan::seconds() const
{
	return static_cast<int>(seconds_);
}

void TimeSpan::set_time(int hours, int minutes, int seconds) 
{
	seconds_ = seconds;
	minutes_ = minutes;
	hours_ = hours; 
}

// Round seconds with decimals to the nearest second
void TimeSpan::round_seconds()
{
	int y = static_cast<int>(seconds_);
	double ans = abs(seconds_ - y);
	if (ans >= 0.5)
	{
		seconds_ = static_cast<int>(seconds_) + 1;
	}
	else
	{
		seconds_ = static_cast<int>(seconds_);
	}
}

//Reallocates any decimals that minutes have into seconds
void TimeSpan::reallocate_minutes()
{
	int y = static_cast<int>(minutes_);
	double ans = abs(minutes_ - y);
	seconds_ = seconds_ + (ans * 100);
	minutes_ = static_cast<int>(minutes_);
}

//Reallocates any decimals that hours have into minutes
void TimeSpan::reallocate_hours()
{
	int y = static_cast<int>(hours_);
	double ans = abs(hours_ - y);
	minutes_ = minutes_ + (ans * 60);
	hours_ = static_cast<int>(hours_);
}


// Round up any time unit over 60 to the next unit for minutes and seconds
// a = smaller unit (ex. minutes)
// b = larger unit (ex. hours)
double TimeSpan::next_unit(double &a, double &b)
{
	double sixty = 60.0;
	while (a >= sixty)
	{
		a = a - sixty;
		b = b + 1; 
	}
	return a, b; 
}

// Puts negative unit against positive unit
// a = smaller unit (ex. minutes)
// b = larger unit (ex. hours)
double TimeSpan::negative(double& a, double& b)
{
	if (b < 0 && a > 0)
	{
		while ((b < 0) && (a > 0))
		{
			b = b + 1;
			a = a - 60;
		}
		return a, b;
	}
	else if (b > 0 && a < 0)
	{
		for (int i = 0; i < (a / 60) + 1; i++)
		{
			a = -(60 - abs(a));
			b = b - 1;
		}
		a = -a; 
		return a, b;
	} 
}


TimeSpan& TimeSpan::operator+=(const TimeSpan& time_span)
{
	double seconds = (seconds_ + time_span.seconds_); 
	double minutes = (minutes_ + time_span.minutes_);
	double hours = (hours_ + time_span.hours_);
	next_unit(seconds, minutes);
	next_unit(minutes, hours);
	set_time(hours, minutes, seconds);
	return *this;
}

TimeSpan TimeSpan::operator+(const TimeSpan& time_span) const
{
	TimeSpan result = *this;
	result += time_span;
	return result;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& time_span)
{
	double seconds = (seconds_ - time_span.seconds_);
	double minutes = (minutes_ - time_span.minutes_);
	double hours = (hours_ - time_span.hours_);
	next_unit(seconds, minutes);
	next_unit(minutes, hours);
	set_time(hours, minutes, seconds);
	return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan& time_span) const
{
	TimeSpan result = *this;
	result -= time_span;
	return result;
} 

bool TimeSpan::operator==(const TimeSpan& time_span) const
{
	return((seconds_ == time_span.seconds_) && (minutes_ == time_span.minutes_)&& (hours_ == time_span.hours_));
}

bool TimeSpan::operator!=(const TimeSpan& time_span) const
{
	return !(*this == time_span);
}

bool TimeSpan::operator<(const TimeSpan& time_span) const
{
	return ((hours_ + (seconds_/100) + (seconds_/10000)) < (time_span.hours_ + (time_span.minutes_/100)+ (time_span.seconds_/10000)));
}

bool TimeSpan::operator<=(const TimeSpan& time_span) const
{
	return ((hours_ + (seconds_ / 100) + (seconds_ / 10000)) <= (time_span.hours_ + (time_span.minutes_ / 100) + (time_span.seconds_ / 10000)));
}

bool TimeSpan::operator>(const TimeSpan& time_span) const
{
	return ((hours_ + (seconds_ / 100) + (seconds_ / 10000)) > (time_span.hours_ + (time_span.minutes_ / 100) + (time_span.seconds_ / 10000)));
}

bool TimeSpan::operator>=(const TimeSpan& time_span) const
{
	return ((hours_ + (seconds_ / 100) + (seconds_ / 10000)) >= (time_span.hours_ + (time_span.minutes_ / 100) + (time_span.seconds_ / 10000)));
}

// Prints out hours, minutes, and seconds
ostream& operator<<(ostream & stream, const TimeSpan & time_span)
{
	stream << "Hours: " << time_span.hours_ << ", Minutes: " << time_span.minutes_ << ", Seconds: " << time_span.seconds_ << endl;
	return stream;
} 




