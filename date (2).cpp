#include "date.h"
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}
Date::~Date()
{}
void Date::print()const
{
	cout << day << "/" << month << "/" << year << endl;
}
Date Date:: operator=(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}