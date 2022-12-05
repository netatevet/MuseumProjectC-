#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "art.h"
class Statue :virtual public Art
{
protected:
	float area, weight;
public:
	Statue();
	Statue(char* artname, char* type, int artyear, float hight, Artist* artist, float area, float weight);
	Statue(const Statue& s);
	virtual ~Statue();
	virtual Statue operator=(const Statue& s);
	virtual const char* get_kind()const;
	virtual float get_weight()const;

};