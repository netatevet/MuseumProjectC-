#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "statue.h"
#include "image.h"
class HangingStatue : public Statue, public Image
{
protected:
	int screws;
public:
	HangingStatue();
	HangingStatue(char* artname, char* type, int artyear, float hight, Artist* artist, float area, float weight, float length, int screws);
	HangingStatue(const HangingStatue& h);
	virtual ~HangingStatue();
	virtual HangingStatue operator=(const HangingStatue& h);
	virtual const char* get_kind()const;
};