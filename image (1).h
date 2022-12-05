#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "art.h"

class Image :virtual public Art
{
protected:
	float length;
public:
	Image();
	Image(char* artname, char* type, int artyear, float hight, Artist* artist, float length);
	Image(const Image& im);
	virtual ~Image();
	virtual Image operator=(const Image& im);
	virtual const char* get_kind()const;
	virtual void print()const;
};