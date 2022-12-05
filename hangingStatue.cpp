#include "hangingStatue.h"
HangingStatue::HangingStatue() :Art(),Statue(), Image()
{
	screws = 0;
}
HangingStatue::HangingStatue(char* artname, char* type, int artyear, float hight, Artist* artist, float area, float weight, float length, int screws) : Art(artname, type, artyear, hight, artist),Statue(artname, type, artyear, hight, artist, area, weight), Image(artname, type, artyear, hight, artist, length)
{
	this->screws = screws;
}
HangingStatue::HangingStatue(const HangingStatue& h) : Statue(h), Image(h)
{
	screws = h.screws;
}
HangingStatue::~HangingStatue()
{
}
HangingStatue HangingStatue::operator=(const HangingStatue& h)
{
	artname = h.artname;
	type = h.type;
	artyear = h.artyear;
	hight = h.hight;
	artist = h.artist;
	area = h.area;
	weight = h.weight;
	length = h.length;
	screws = h.screws;
	return *this;
}
const char* HangingStatue::get_kind()const
{
	return "hangingStatue";
}