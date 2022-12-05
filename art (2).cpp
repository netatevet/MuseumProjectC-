#include "art.h"
#include <string>
Art::Art()
{
	artname = NULL;
	type = NULL;
	artyear = 0;
	hight = 0;
	artist = NULL;
}
Art::Art(char* artname, char* type, int artyear, float hight, Artist* artist)
{
	this->artname = new char[strlen(artname) + 1];//allocation of string name
	if (this->artname != NULL)//if the allocation workes
		strcpy(this->artname, artname);//copy the name string
	this->type = new char[strlen(type) + 1];//allocation of string name
	if (this->type != NULL)//if the allocation workes
		strcpy(this->type, type);//copy the name string


	this->artyear = artyear;
	this->hight = hight;
	this->artist = artist;
}
Art::Art(const Art& a)
{
	this->artname = new char[strlen(a.artname) + 1];
	if (this->artname != NULL)
		strcpy(this->artname, a.artname);
	this->type = new char[strlen(a.type) + 1];
	if (this->type != NULL)
		strcpy(this->type, a.type);
	artyear = a.artyear;
	hight = a.hight;
	artist = a.artist;
}
Art::~Art()
{}
void Art::print()const
{
	cout << "name of art: " << artname << " type: " << type << " year which the work was created: " << artyear << " hight: " << hight << endl;
}
Art Art::operator=(const Art& a)
{
	artname = a.artname;
	type = a.type;
	artyear = a.artyear;
	hight = a.hight;
	artist = a.artist;
	return *this;
}
char* Art::get_name()const
{
	return artname;
}
const char* Art::get_kind()const
{
	return "art";
}
char* Art::get_type()const
{
	return type;
}
Artist* Art::get_artist()const
{
	return artist;
}