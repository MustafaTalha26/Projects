//////////////////////////////////////////
// Mustafa Talha MERT
// 1306200015
// Date: 2021.05.18
// IDE: Visual Studio 2019
///////////////////////////////////////////
// Node sýnýrým 9
// Yol sýnýrým 49
// Yol uzunluðum ise en fazla 49
//////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
string::size_type sz;

struct nodes
{
	string ismi = "";
	string ýrk = " ";
	int num = 0;
} noder[9];

struct paths
{
	string rows = "";
	int button = 0;
} pathers[9];

struct roads
{
	int first = 0;
	int second = 0;
} rods[50];

int counter = 0;

string arama1(string line)
{
	string rest = "";
	char delim = ',';
	line = line + delim;
	for (int x = 0; x < line.length(); x++)
	{
		if (line.at(x) == ',')
		{
			for (int c = x - 2; c < x; c++)
			{
				noder[counter].ismi = noder[counter].ismi + line.at(c);
			}
			noder[counter].num = counter + 1;
			counter++;
		}
	}
	return "";
}

int karma = 0;
string arama2(string line)
{
	string shoter = "";
	string victim = "";
	for (int x = 0; x < line.length(); x++)
	{
		if (line.at(x) == '-')
		{
			for (int c = 0; c < 2; c++)
			{
				shoter = shoter + line.at(c);
			}
			for (int z = x + 2; z < line.length(); z++)
			{
				victim = victim + line.at(z);
			}
			for (int x = 0; x < 9; x++)
			{
				if (noder[x].ismi == shoter)
				{
					rods[karma].first = noder[x].num;
				}
				if (noder[x].ismi == victim)
				{
					rods[karma].second = noder[x].num;
				}
			}
		}
	}
	karma++;
	return "";
}

int ix = 0;
int arama3(int ac, int n = 0, int axx[50] = { 0 })
{
	int niyeya = 0;
	int yesno = 0;
	if (n == 0)
	{
		for (int x = 0; x < 9; x++)
		{
			if (pathers[ix].rows.at(0) == noder[x].ýrk.at(0))
			{
				for (int c = 0; c < 9; c++)
				{
					if (pathers[ix].rows.at(1) == noder[c].ýrk.at(0))
					{
						int ab = noder[x].num;
						int bb = noder[c].num;
						for (int z = 0; z < 50; z++)
						{
							if (ab == rods[z].first)
							{
								if (bb == rods[z].second)
								{
									if (pathers[ix].rows.at(2) == '.')
									{
										pathers[ix].button = 1;
									}
									int* abb;
									abb = new int[50];
									abb[0] = z;
									arama3(bb, 2, abb);
									delete[] abb;
								}
							}
						}
					}
				}
			}
		}
	}
	if (n > 50)
	{
		return 0;
	}
	if (n != 0)
	{
		if (pathers[ix].rows.at(n) == '.')
		{
			pathers[ix].button = 1;
		}
		for (int c = 0; c < 9; c++)
		{
			if (pathers[ix].rows.at(n) == noder[c].ýrk.at(0))
			{
				int bb = noder[c].num;
				for (int z = 0; z < 50; z++)
				{
					if (ac == rods[z].first)
					{
						if (bb == rods[z].second)
						{
							int ajax = 1;
							for (int zz = 0; zz < 50; zz++)
							{
								if (axx[zz] == z)
								{
									ajax = 0;
								}
							}
							if (ajax == 1)
							{
								int* abb;
								abb = new int[50];
								for (int xx = 0; xx < 50; xx++)
								{
									abb[xx] = axx[xx];
								}
								abb[n - 1] = z;
								arama3(bb, n + 1, abb);
								delete[] abb;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int rounder = 0;
string duzelt(string line)
{
	line = line + '.';
	pathers[rounder].rows = line;
	rounder++;
	return "";
}

string racebound()
{
	for (int x = 0; x < counter; x++)
	{
		noder[x].ýrk = noder[x].ismi.at(0);
	}
	return "";
}

int main()
{
	ifstream girdi;
	ofstream cýktý;
	string line;
	string paths = "Paths:";
	int pather = 0;

	girdi.open("input.txt");

	getline(girdi, line);
	arama1(line);
	racebound();
	while (getline(girdi, line))
	{
		if (line == paths)
		{
			break;
		}
		arama2(line);
	}
	while (getline(girdi, line))
	{
		duzelt(line);
		arama3(0, 0);
		ix++;
	}
	cýktý.open("output.txt");
	for (int x = 0; x < 9; x++)
	{
		if (pathers[x].rows != "")
		{
			if (pathers[x].button == 0)
			{
				string noktasiz = "";
				for (int c = 0; c < pathers[x].rows.length(); c++)
				{
					if (pathers[x].rows.at(c) != '.')
					{
						noktasiz = noktasiz + pathers[x].rows.at(c);
					}
				}
				cýktý << noktasiz << " [NO]" << endl;
			}
			if (pathers[x].button == 1)
			{
				string noktasiz = "";
				for (int c = 0; c < pathers[x].rows.length(); c++)
				{
					if (pathers[x].rows.at(c) != '.')
					{
						noktasiz = noktasiz + pathers[x].rows.at(c);
					}
				}
				cýktý << noktasiz << " [YES]" << endl;
			}
		}
	}
	return 0;
}