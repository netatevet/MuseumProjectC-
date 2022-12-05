#include "museum.h"
#include "artist.h"
#include <string>
Museum::Museum()
{
	museumArts = NULL;
	numOfMuseumArts = 0;
	numOfArtists = 0;
	artists = NULL;
}
Artist* Museum::findArtist(char* name) const
{
	for (int i = 0; i < numOfArtists; i++)
	{
		if (strcmp(artists[i]->name, name) == 0)
			return artists[i];
	}
	return NULL;
}

void Museum::addArtist(Artist* a)
{
	Artist** new_arr = NULL;
	new_arr = new Artist * [numOfArtists + 1];//יצירת מערך זמני שגדול ב1
	if (new_arr != NULL)
	{
		for (int i = 0; i < numOfArtists; i++)
			new_arr[i] = artists[i];//העתקה אל המערך הזמני
		new_arr[numOfArtists] = a;//הוספת האמן החדש
		delete[]artists;//מחיקה של מערך האמנים
		artists = new Artist * [numOfArtists + 1];
		if (artists != NULL)
		{
			for (int i = 0; i <= numOfArtists; i++)
				artists[i] = new_arr[i];//העתקה אליו מחדש כולל האמן החדש
			numOfArtists++;
		}
	}
}
void Museum::addArts(Art* a)
{
	Art** new_arr = NULL;
	new_arr = new Art * [numOfMuseumArts + 1];
	if (new_arr != NULL)
	{
		for (int i = 0; i < numOfMuseumArts; i++)
			new_arr[i] = museumArts[i];
		new_arr[numOfArtists] = a;//הוספת יצירה חדשה
		delete[]museumArts;
		museumArts = new Art * [numOfMuseumArts + 1];
		if (museumArts != NULL)
		{
			for (int i = 0; i <= numOfMuseumArts; i++)
				museumArts[i] = new_arr[i];
			numOfMuseumArts++;
		}
	}
	a->get_artist()->addArt(a);
}
void Museum::deleteArts(int index)
{
	Art** new_arr = NULL;
	new_arr = new Art * [numOfMuseumArts - 1];
	if (new_arr != NULL)
	{
		for (int i = 0; i < numOfMuseumArts - 1; i++)
			if (i != index)//לא מעתיק את היצירה שבאינדקס
				new_arr[i] = museumArts[i];
		delete[]museumArts;
		museumArts = new Art * [numOfMuseumArts - 1];
		if (museumArts != NULL)
		{
			for (int i = 0; i <= numOfMuseumArts - 1; i++)
				museumArts[i] = new_arr[i];
			numOfMuseumArts--;
		}
	}
}
void Museum::printArtist()const
{
	for (int i = 0; i < numOfArtists; i++)
		if ((artists[i]->numOfArts) > 0)
			artists[i]->print();
}
void Museum::printArts()const
{
	for (int i = 0; i < numOfMuseumArts; i++)
		museumArts[i]->print();
}
void Museum::printImages()const
{
	for (int i = 0; i < numOfMuseumArts; i++)
		if ((strcmp(museumArts[i]->get_kind(), "image") == 0) || (strcmp(museumArts[i]->get_kind(), "hangingStatue") == 0))
			museumArts[i]->print();
}
void Museum::printStatues()const
{
	for (int i = 0; i < numOfMuseumArts; i++)
		if ((strcmp(museumArts[i]->get_kind(), "statue") == 0) || (strcmp(museumArts[i]->get_kind(), "hangingStatue") == 0))
			museumArts[i]->print();
}
void Museum::printType(char* t)const
{
	for (int i = 0; i < numOfMuseumArts; i++)
		if (strcmp(museumArts[i]->get_type(),t)==0)
			museumArts[i]->print();
}
void Museum::printArtistImages()const
{
	int flag;
	for (int i = 0; i < numOfArtists; i++)
	{
		flag = 0;
		for (int j = 0; j < artists[i]->numOfArts; j++)
			if ((strcmp(artists[i]->arts[j]->get_kind(), "image") == 0) || (strcmp(artists[i]->arts[j]->get_kind(), "hangingStatue") == 0))
				flag++;
		if (flag > 0)
			artists[i]->print();
	}
}
void Museum::printArtistStatues()const
{
	int flag;
	for (int i = 0; i < numOfArtists; i++)
	{
		flag = 0;
		for (int j = 0; j < artists[i]->numOfArts; j++)
			if ((strcmp(artists[i]->arts[j]->get_kind(), "statue") == 0) || (strcmp(artists[i]->arts[j]->get_kind(), "hangingStatue") == 0))
				flag++;
		if (flag > 0)
			artists[i]->print();
	}
}
void Museum::printStatues(float w)const
{
	for (int i = 0; i < numOfMuseumArts; i++)
		if ((strcmp(museumArts[i]->get_kind(), "statue") == 0) || (strcmp(museumArts[i]->get_kind(), "hangingStatue") == 0))
			if ((dynamic_cast<Statue*>(museumArts[i])->get_weight()) > w)
				museumArts[i]->print();
}
void Museum::manu()
{
	int c=0, day, month, year, artyear, screws, index;
	char name[20];
	float length, hight, weight, area;
	char name1[10], type[10];
	Artist* ar = NULL;
	while (c != 12)
	{
		cout << "enter number: " << endl << "1-add artist" << endl << "2-add art" << endl << "3-remove art" << endl << "4-print all the artist that have art" << endl << "5- print all arts" << endl << "6-print images" << endl << "7- print statues" << endl << "8-print arts with type" << endl << "9-print all the artists that have image" << endl << "10-print all the artists that have statue" << endl << "11-print all the statues over weight" << endl << "12-exit" << endl;;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			cout << "enter name" << endl;
			cin >> name;
			cout << "enter birthday" << endl;
			cin >> day >> month >> year;
			Date b(day, month, year);
			cout << "enter death day" << endl;
			cin >> day >> month >> year;
			Date d(day, month, year);
			Artist a(name, b, d);
			addArtist(&a);
			break;
		}
		case 2:
		{
			int c1;
			cout << "enter number" << endl << "1-image " << "2-statue " << "3-hanging statue" << endl;
			cin >> c1;
			cout << "enter name of art" << endl;
			cin >> name1;
			cout << "enter type" << endl;
			cin >> type;
			cout << "enter year" << endl;
			cin >> artyear;
			cout << "enter artist" << endl;
			cout << "enter name" << endl;
			cin >> name;
			ar=findArtist(name);
			if (ar != NULL)
			{
				cout << "enter hight" << endl;
				cin >> hight;
				if (c1 == 1)
				{
					cout << "enter length" << endl;
					cin >> length;
					Image x(name1, type, artyear, hight, ar, length);
					addArts(&x);
				}
				if (c1 == 2)
				{
					cout << "enter weight" << endl;
					cin >> weight;
					cout << "enter area" << endl;
					cin >> area;
					Statue x(name1, type, artyear, hight, ar, area, weight);
					addArts(&x);
				}
				if (c1 == 3)
				{
					cout << "enter length" << endl;
					cin >> length;
					cout << "enter weight" << endl;
					cin >> weight;
					cout << "enter area" << endl;
					cin >> area;
					cout << "enter num of screws" << endl;
					cin >> screws;
					HangingStatue x(name1, type, artyear, hight, ar, area, weight, length, screws);
					addArts(&x);
				}
			}
			else
				cout << "not found"<<endl;
			break;
		}
		case 3:
		{
			cout << "enter index" << endl;
			cin >> index;
			deleteArts(index);
			break;
		}
		case 4:
		{
			printArtist();
			break;
		}
		case 5:
		{
			printArts();
			break;
		}
		case 6:
		{
			printImages();
			break;
		}
		case 7:
		{
			printStatues();
			break;
		}
		case 8:
		{
			cout << "enter type" << endl;
			cin >> type;
			printType(type);
			break;
		}
		case 9:
		{
			printArtistImages();
			break;
		}
		case 10:
		{
			printArtistStatues();
			break;
		}
		case 11:
		{
			cout << "enter weight" << endl;
			cin >> weight;
			printStatues(weight);
			break;
		}
		case 12:
		{
			break;
		}
		}
	}
}