#include "image.h"
Image::Image() : Art()
{
	length = 0;
}
Image::Image(char* artname, char* type, int artyear, float hight, Artist* artist, float length) : Art(artname, type, artyear, hight, artist)
{
	this->length = length;
}
Image::Image(const Image& im) : Art(im)
{
	length = im.length;
}
Image::~Image()
{}
Image Image::operator=(const Image& im)
{
	artname = im.artname;
	type = im.type;
	artyear = im.artyear;
	hight = im.hight;
	artist = im.artist;
	length = im.length;
	return *this;
}
const char* Image::get_kind()const
{
	return "image";
}
void Image::print()const
{
	Art::print();
	cout << "length" << length << endl;
}