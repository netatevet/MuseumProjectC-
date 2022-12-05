#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include "art.h"
#include "artist.h"
#include "hangingStatue.h"
#include "statue.h"
#include "image.h"
#include "date.h"
class Museum
{
protected:
	Art** museumArts;
	Artist** artists;
	int numOfMuseumArts, numOfArtists;
public:
	Museum();
	void addArtist(Artist* a);
	void addArts(Art* a);
	void deleteArts(int index);
	void printArtist()const;
	void printArts()const;
	void printImages()const;
	void printStatues()const;
	/*void printArtistArts()const;*/
	void printType(char* t)const;
	void printArtistImages()const;
	void printArtistStatues()const;
	void printStatues(float w)const;
	void manu();
	Artist* findArtist(char* name) const;

};