#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "artist.h"
#include <string>
class Artist;
class Art
{
protected:
	char *artname, *type;
	int artyear;
	float hight;
	Artist (*artist);
public:
	Art();
	Art(char* artname, char* type, int artyear, float hight, Artist* artist);
	Art(const Art &a);
	~Art();
	virtual void print()const;
	virtual Art operator=(const Art& a);
	char* get_name()const;
	virtual const char* get_kind()const;
	virtual char* get_type()const;
	Artist* get_artist()const;
};
