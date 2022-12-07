#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<const char*> yamanoteLine =
	{ "Tokyo","Kanda","Akihabara", "Okachimachi", "Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome","Sugamo",
		"Otuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro","Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho\n\n" };

	cout << "----1970”N----\n";

	for (auto itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		cout << *itr << "\n";
	}


	for (auto itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (strcmp(*itr, "Tabata") == 0)
		{
			itr = yamanoteLine.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}

	cout << "----2019”N----\n";

	for (auto itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	
	for (auto itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (strcmp(*itr, "Tamachi") == 0)
		{
			itr = yamanoteLine.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}

	cout << "----2022”N----\n";

	for (auto itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	return 0;
}