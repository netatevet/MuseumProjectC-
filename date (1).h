#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Date
{
protected:
	int day, month, year;
public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& d);
	~Date();
	virtual void print()const;
	virtual Date operator=(const Date& d);
};