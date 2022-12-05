#include "statue.h"
Statue::Statue() :Art()
{
	area = 0;
	weight = 0;
}
Statue::Statue(char* artname, char* type, int artyear, float hight, Artist* artist, float area, float weight) : Art(artname, type, artyear, hight, artist)
{
	this->area = area;
	this->weight = weight;
}
Statue::Statue(const Statue& s) : Art(s)
{
	area = s.area;
	weight = s.weight;
}
Statue::~Statue()
{}
Statue Statue::operator=(const Statue& s)
{
	artname = s.artname;
	type = s.type;
	artyear = s.artyear;
	hight = s.hight;
	artist = s.artist;
	area = s.area;
	weight = s.weight;
	return *this;
}
const char* Statue::get_kind()const
{
	return "statue";
}
float Statue::get_weight()const
{
	return weight;
}