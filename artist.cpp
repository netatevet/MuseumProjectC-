#include "artist.h"
Artist::Artist()
{
	name = new char[2];
	strcpy(name, " ");
	Date x(0, 0, 0);
	birthday = x;
	death = x;
	arts = NULL;
	numOfArts = 0;
}
Artist::Artist(char* name, Date birthday, Date death)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->birthday = birthday;
	this->death = death;
	this->arts = NULL;
	this->numOfArts = 0;
}
Artist::Artist(const Artist& a)
{
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->birthday = a.birthday;
	this->death = a.death;
	this->arts = new Art * [a.numOfArts];
	if (this->arts != NULL)
	{
		for (int i = 0; i < a.numOfArts; i++)
			this->arts[i] = a.arts[i];
	}
	this->numOfArts = a.numOfArts;
}
Artist::~Artist()
{
	if (arts != NULL)
		delete[]arts;
}
void Artist::print()const
{
	cout << "name of artist: " << name << " birthday: ";
	birthday.print();
	cout << " daeth day:  ";
	death.print();
	if (numOfArts > 0)
	{
		for (int i = 0; i < numOfArts; i++)
			arts[i]->print();
	}
}
Artist Artist:: operator=(const Artist& a)
{
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->birthday = a.birthday;
	this->death = a.death;
	this->arts = new Art * [a.numOfArts];
	if (this->arts != NULL)
	{
		for (int i = 0; i < a.numOfArts; i++)
			this->arts[i] = a.arts[i];
	}
	this->numOfArts = a.numOfArts;
	return *this;
}
void Artist::addArt(Art* a)
{
	Art** new_arr = NULL;
	new_arr = new Art * [numOfArts + 1];
	if (new_arr != NULL)
	{
		for (int i = 0; i < numOfArts; i++)
			new_arr[i] = arts[i];
		new_arr[numOfArts] = a;
		delete[]arts;
		arts = new Art * [numOfArts + 1];
		if (arts != NULL)
		{
			for (int i = 0; i <= numOfArts; i++)
				arts[i] = new_arr[i];
			numOfArts++;
		}
	}
}
int Artist::get_numOfArts()const
{
	return numOfArts;
}