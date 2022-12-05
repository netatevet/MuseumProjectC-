#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "date.h"
#include "art.h"
#include <string>
using namespace std;
class Art;
class Artist
{
protected:
	char* name;
	Date birthday, death;
	Art **arts;
	int numOfArts;
public:
	Artist();
	Artist(char* name, Date birthday, Date death);
	Artist(const Artist& a);
	~Artist();
	virtual void print()const;
	virtual Artist operator=(const Artist& a);
	void addArt(Art (*a));
	int get_numOfArts()const;
	friend class Museum;
};