#include <cassert>
#include <iostream>
#include <locale>
using namespace std;
const double eps = pow(10, -4);
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
	
}

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert(minutes >= 0);
	assert(minutes < 60);
	assert(seconds >= 0);
	assert(seconds < 60);
	return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
        
	assert(hours >= 0);
	while (hours >= 24)
	{
		hours -= 24;
	}
	return hours;
}

int get_hours(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
	{
		seconds -= 3600;
		res += 1;
	}
	return res;
}

int get_minutes(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
		seconds -= 3600;

	while (seconds <= 60)
	{
		seconds -= 60;
		res += 1;
	}
	return res;
}
/*
int get_seconds(int seconds)
{
	int res = 0;
	while (seconds <= 3600)
		seconds -= 3600;

	while (seconds <= 60)
		seconds -= 60;

	return seconds;
}
double time_to_utc(int utc_offset, double time)
{

	double res = time - utc_offset;
	if (res >= 24)
		res -= 24;
	return (res);
}



double time_from_utc(int utc_offset, double time)
{
	
	double res = time + utc_offset;
	if (res >= 24)
		res -= 24;
	if (res < 0)
		res += 24;
	return (res);
}
double equals(double a, double b)
{
	return(abs(a - b) < eps);
}*/
int main()
{
	locale::global(std::locale(""));
	/*Тесты для seconds_difference*/
	assert(equals(seconds_difference(1800.0, 3600.0),1800.0));
	assert(equals(seconds_difference(3600.0, 1800.0),-1800.0)); 
	assert(equals(seconds_difference(1800.0, 2160.0), 360.0));
	assert(equals(seconds_difference(1800.0, 1800.0), 0.0));
	cout << "Тесты для seconds_difference пройдены!" << endl;
	/*Тесты для hours_difference*/
	assert(equals(hours_difference(1800.0, 3600.0),0.5));
	assert(equals(hours_difference(3600.0, 1800.0),-0.5));
	assert(equals(hours_difference(1800.0, 2160.0),0.1));
	assert(equals(hours_difference(1800.0, 1800.0),0.0));
	cout << "Тесты для hours_difference пройдены!" << endl;
	/*Тесты для to_float_hours*/
	assert(equals(to_float_hours(0, 15, 0),0.25));
	assert(equals(to_float_hours(2, 45, 9),2.7525));
	assert(equals(to_float_hours(1, 0, 36),1.01));
	cout << "Тесты для to_float_hours пройдены!" << endl;
	/*Тесты для to_24_hour_clock*/
	assert(equals(to_24_hour_clock(24),0));
	assert(equals(to_24_hour_clock(48),0));
	assert(equals(to_24_hour_clock(25),1));
	assert(equals(to_24_hour_clock(4),4));
	assert(equals(to_24_hour_clock(28.5),4.5));
	cout << "Тесты для to_24_hour_clock пройдены!" << endl;
	/*Тесты для time_to_utc*/
	assert(equals(time_to_utc(+0, 12.0), 12.0));
	assert(equals(time_to_utc(+1, 12.0), 11.0));
	assert(equals(time_to_utc(-1, 12.0), 13.0));
	assert(equals(time_to_utc(-11, 18.0), 5.0));
	assert(equals(time_to_utc(-1, 0.0), 1.0));
	assert(equals(time_to_utc(-1, 23.0), 0.0));
	cout << "Тесты для time_to_utc пройдены!" << endl;
	/*Тесты для time_to_utc*/
	assert(equals(time_from_utc(+0, 12.0), 12.0));
	assert(equals(time_from_utc(+1, 12.0), 13.0));
	assert(equals(time_from_utc(-1, 12.0), 11.0));
	assert(equals(time_from_utc(+6, 6.0), 12.0));
	assert(equals(time_from_utc(-7, 6.0), 23.0));
	assert(equals(time_from_utc(-1, 0.0), 23.0));
	assert(equals(time_from_utc(-1, 23.0), 22.0));
	assert(equals(time_from_utc(+1, 23.0), 0.0));
	cout << "Тесты для time_from_utc пройдены!" << endl;
	system("pause");

}
