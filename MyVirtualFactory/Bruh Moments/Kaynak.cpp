//////////////////////////////////////////
// Mustafa Talha MERT
// 1306200015
// Date: 2021.05.26
// IDE: Visual Studio 2019
///////////////////////////////////////////
// Operasyon s�n�r�m 50.
// Setupdur s�n�r�m 50.
// Order s�n�r�m 200.
// Fonksiyonun �st�ndeki a��klamalar fonksiyon hakk�nda basit bilgiler verir.
// Y�ntemim ayn� deadline s�relerine sahip orderlar� bir sepete atmak ile ba�lar.
// Order� ger�ekle�tirecek operasyon kendisine ait �ncelik listesinden sepette var olan en y�ksek �ncelikli order� se�er.
// Eleman sepetten silinir ve eleman� ger�ekle�tirecek operasyon bir sonraki i�lem i�in devam eder.
// Sepette order kalmazsa bir sonraki deadline'a ait orderler sepete konur ve s�ralanmam�� hi�bir order kalmay�ncaya kadar devam eder.
// Ama� operasyon ge�i�lerinde en d���k s�reli ge�i� i�lemlerini yakalayarak s�reden y�ksek oranda kar etmektir.
// Bilgisayar performans�na zarar vermemesi ve vakit �almamas� amac�yla structure boyutlar�n� d���k tuttum ama 
// istenildi�i taktirde bu boyutlar algoritmaya hasar vermeden b�y�t�lebilir.(1 milyon sipari� hatr� say�l�r miktarda s�re al�yor.) 
//////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
string::size_type sz;

//okuyucu makine ge�i�
struct operasyon 
{
	int num = 0;
	int perm = 0;
}ops[50];

//okuyucu makineler aras� ge�i�
struct setuptime
{
	int first = 0;
	int second = 0;
	int dur = 0;
}setups[1225];

//okuyucu sipari�ler
struct sp
{
	int num = 0;
	int amount = 0;
	int which = 0;
	int last = 0;
}orders[200];

//sipari�leri s�ralad���m liste
struct lin
{
	int num = 0;
	int last = 0;
	int opss = 0;
}line[200];

//makine ge�i�leri �ncelik listesi
struct priolist
{
	int one = 0;
	int arr[50] = {0};
}prio[50];

//siprai� vakitlerine g�re ay�r�p bunun i�inde saklad�m
struct tarih
{
	int last = 0;
	int items[50] = { 0 };
}bo[50];

//isminden �t�r� �z�r dilerim :D ge�ici sepet olarak kulland�m
struct banakafay�yedirmeden�ncekisonliste
{
	int ab = 0;
}avi[50];

//yard�mc� bo�luk silen
string engel(string dirsek)
{
	int counter = 0;
	string yenisat�r = "";
	while (counter < dirsek.length())
	{
		if (dirsek.at(counter) != ' ')
		{
			yenisat�r += dirsek.at(counter);
		}
		counter++;
	}
	return yenisat�r;
}

//makine i�lemi okuyucu
int oper = 0;
string operation(string line)
{
	string left = "";
	string right = "";
	for (int x = 0; x < line.length(); x++)
	{
		if (line.at(x) == ';')
		{
			for (int z = 0; z < x; z++)
			{
				left += line.at(z);
			}
			for (int c = x + 1; c < line.length(); c++)
			{
				right += line.at(c);
			}
		}
	}
	oper++;
	ops[oper].num = stoi(left);
	ops[oper].perm = stoi(right);
	return "";
}

//makine ge�i�leri okuyucu
int rop = 0;
string setup(string line)
{
	int red = 0;
	int bruh = 0;
	string left = "";
	string right = "";
	for (int x = 0; x < line.length(); x++)
	{
		if (line.at(x) == ';')
		{
			bruh++;
		}
	}
	if (bruh == 1)
	{
		for (int x = 0; x < line.length(); x++)
		{
			if (line.at(x) == ';')
			{
				for (int z = 0; z < x; z++)
				{
					left = left + line.at(z);
				}
				for (int c = x + 1; c < line.length(); c++)
				{
					right = right +line.at(c);
				}
				setups[rop].second = stoi(left);
				setups[rop].dur = stoi(right);
				rop++;
				return "";
			}
		}
	}
	if (bruh == 2)
	{
		for (int x = 0; x < line.length(); x++)
		{
			if (line.at(x) == ';')
			{
				red++;
				if (red == 1)
				{
					for (int z = 0; z < x; z++)
					{
						left += line.at(z);
					}
					for (int c = x + 1; c < line.length(); c++)
					{
						right += line.at(c);
					}
					setups[rop].first = stoi(left);
					return setup(right);
				}
			}
		}
	}
	return "";
}

//sipari� dosyas� okuyucu
int buff = 0;
string order(string line)
{
	int red = 0;
	int bruh = 0;
	string left = "";
	string right = "";
	for (int x = 0; x < line.length(); x++)
	{
		if (line.at(x) == ';')
		{
			bruh++;
		}
	}
	if (bruh == 1)
	{
		for (int x = 0; x < line.length(); x++)
		{
			if (line.at(x) == ';')
			{
				for (int z = 0; z < x; z++)
				{
					left = left + line.at(z);
				}
				for (int c = x + 1; c < line.length(); c++)
				{
					right = right + line.at(c);
				}
				orders[buff].which = stoi(left);
				orders[buff].last = stoi(right);
				buff++;
				return "";
			}
		}
	}
	if (bruh == 2)
	{
		for (int x = 0; x < line.length(); x++)
		{
			if (line.at(x) == ';')
			{
				red++;
				if (red == 1)
				{
					for (int z = 0; z < x; z++)
					{
						left += line.at(z);
					}
					for (int c = x + 1; c < line.length(); c++)
					{
						right += line.at(c);
					}
					orders[buff].amount = stoi(left);
					return order(right);
				}
			}
		}
	}
	if (bruh == 3)
	{
		for (int x = 0; x < line.length(); x++)
		{
			if (line.at(x) == ';')
			{
				red++;
				if (red == 1)
				{
					for (int z = 0; z < x; z++)
					{
						left += line.at(z);
					}
					for (int c = x + 1; c < line.length(); c++)
					{
						right += line.at(c);
					}
					orders[buff].num = stoi(left);
					return order(right);
				}
			}
		}
	}
	return "";
}

//makine tak ��kar �ncelik hesab�
void priolister(int a = 1)
{
	int brr[50][2] = { 0, 0 };
	int ab = 0;
	brr[ab][0] = ops[a].num;
	brr[ab][1] = 0;
	for (int x = 0; x < 50; x++)
	{
		if (a == setups[x].second)
		{
			ab++;
			brr[ab][0] = setups[x].first;
			brr[ab][1] = setups[x].dur;
		}
		if (a == setups[x].first)
		{
			ab++;
			brr[ab][0] = setups[x].second;
			brr[ab][1] = setups[x].dur;
		}
	}
	for (int z = 0; z < 50; z++)
	{
		for (int c = 0; c < 50; c++)
		{
			if (brr[z][1] < brr[c][1])
			{
				if (brr[z][0] != 0 && brr[c][0] != 0)
				{
					int temp = brr[z][1];
					brr[z][1] = brr[c][1];
					brr[c][1] = temp;
					temp = brr[z][0];
					brr[z][0] = brr[c][0];
					brr[c][0] = temp;
				}
			}
		}
	}
	prio[a].one = ops[a].num;
	for (int x = 0; x < 50; x++)
	{
		prio[a].arr[x] = brr[x][0];
	}
	/*for (int x = 0; x < 50; x++)
	{
		if (prio[a].one != 0)
		{
			cout << "bunun: " << prio[a].one << endl;
			for (int c = 0; c < 50; c++)
			{
				if (prio[a].arr[c] != 0)
				{
					cout << prio[a].arr[c] << endl;
				}
			}
		}
	}*/
}

//okuyucular�n d�zg�n �al��t���n� kontrol etmek i�in
void check()
{
	for (int x = 0; x < 50; x++)
	{
		if (ops[x].num != 0)
		{
			cout << endl;
			cout << "opsnum: " << ops[x].num << endl;
			cout << "opsperm: " << ops[x].perm << endl;
		}
	}
	for (int x = 0; x < 1225; x++)
	{
		if (setups[x].first != 0)
		{
			cout << endl;
			cout << "first: " << setups[x].first << endl;
			cout << "second: " << setups[x].second << endl;
			cout << "dur: " << setups[x].dur << endl;
		}
	}
	for (int x = 0; x < 200; x++)
	{
		if (orders[x].num != 0)
		{
			cout << endl;
			cout << "num: " << orders[x].num << endl;
			cout << "amount: " << orders[x].amount << endl;
			cout << "which: " << orders[x].which << endl;
			cout << "last: " << orders[x].last << endl;
		}
	}
}

//ayn� s�reye g�re 
void laster()
{
	int cx = 0;
	int sayi = 1;
	int dill = 0;
	int arra[50] = { 0 };
	for (int x = 0; x < 200; x++)
	{
		if (arra[0] != 0)
		{
			for (int z = 0; z < 50; z++)
			{
				if (arra[z] == orders[x].last)
				{
					dill = 1;
				}
			}
			if (dill == 0)
			{
				arra[sayi] = orders[x].last;
				sayi++;
			}
			if (dill == 1)
			{
				dill = 0;
			}
		}
		if (arra[0] == 0)
		{
			arra[0] = orders[0].last;
		}
	}
	for (int x = 0; x < 50; x++)
	{
		if (arra[x] != 0)
		{
			bo[x].last = arra[x];
		}
	}
	for (int x = 0; x < 50; x++)
	{
		if (bo[x].last != 0)
		{
			for (int c = 0; c < 20; c++)
			{
				if (bo[x].last == orders[c].last)
				{
					bo[x].items[cx] = orders[c].num;
					cx++;
				}
			}
		}
		cx = 0;
	}
}

//sonraki algoritma i�lemleri i�in kulland���m kontrol fonksiyonu
int ah()
{
	for (int x = 0; x < 200; x++)
	{
		if (line[x].num != 0)
		{
			cout << line[x].num << endl;
		}
	}
	for (int x = 0; x < 50; x++)
	{
		if (bo[x].last != 0)
		{
			cout << bo[x].last << endl;
			for (int c = 0; c < 50; c++)
			{
				if (bo[x].items[c] != 0)
				{
					cout << "a: " << bo[x].items[c] << endl;
				}
			}
		}
	}
	for (int x = 0; x < 50; x++)
	{
		if (prio[x].one != 0)
		{
			cout << prio[x].one << "greeet" << endl;
			for (int c = 0; c < 50; c++)
			{
				if (prio[x].arr[c] != 0)
				{
					cout << "b: " << prio[x].arr[c] << endl;
				}
			}
		}
	}
	return 0;
}

//en son b�t�n i�lemler bittikten sonra elimdeki liste
int bus()
{
	for (int x = 0; x < 200; x++)
	{
		if (line[x].num != 0)
		{
			cout << line[x].num << endl;
		}
	}
	return 0;
}

//�st�nde �ok u�ra�t���m fonksiyon
//Ayn� deadline tarihindeki sipari�leri sepete koyar. Sepet bo�alana kadar bir �nceki siprai�in �al��t��� makinenin �ncelik ->
//listesindeki en y�ksek �ncelikli eleman� sepetten bulur ve listenin i�ine yazar. Yaz�lan eleman sepetten silinir.
//Sepet bo�al�nca bir sonraki tarihin elemanlar�n� koyar ve bu i�lem sipari� kalmay�ncaya kadar devam eder.
//Ama� makine kurulum vakitlerinde zaman tasarrufu etmektir. �stenilen sonu� ��kmazsa algoritman�n s�n�rlar y�z�nden olabilir.
int global = 0;
int mist = -1;
int boi�i(int ilk = 0)
{
	int yes = 0;
	int gecici = 0;
	int tikitak = 0;
	int dolu = 0;
	for (int x = 0; x < 50; x++)
	{
		if (avi[x].ab != 0)
		{
			dolu = 1;
		}
	}
	if (dolu == 0)
	{
		mist++;
		for (int x = 0; x < 50; x++)
		{
			avi[x].ab = bo[mist].items[x];
			/*if (avi[x].ab != 0)
			{
				cout << avi[x].ab << endl;
			}*/
		}
		/*for (int x = 0; x < 50; x++)
		{
			if (avi[x].ab != 0)
			{
				cout << avi[x].ab << "aaaa" << endl;
			}
		}*/
		dolu = 1;
	}
	//d�nk� ben diyor ki orderlar� nas�l kontrol ediyorsun yani 
	if (dolu == 1)
	{
		if (ilk == 0)
		{
			ilk = bo[mist].items[0];
		}
		if (ilk != 0)
		{
			for (int x = 0; x < 50; x++)
			{
				if (ilk == prio[x].one)
				{
					yes = x;
				}
			}
			for (int c = 0; c < 50; c++)
			{
				for (int a = 0; a < 200; a++)
				{
					if (orders[a].num != 0 && avi[c].ab != 0)
					{
						/*cout << orders[a].num << "--" << avi[c].ab << endl;*/
						if (orders[a].num == avi[c].ab)
						{
							/*cout << avi[c].ab << endl;*/
							for (int z = 0; z < 50; z++)
							{
								if (orders[a].which != 0 && prio[yes].arr[z] != 0)
								{
									if (orders[a].which == prio[yes].arr[z])
									{
										if (tikitak == 0)
										{
											tikitak = 1;
											line[global].num = avi[c].ab;
											global++;
											gecici = orders[a].which;
											avi[c].ab = 0;
											boi�i(gecici);
										}
									}
								}
							}
						}
					}
				}
			}

		}
	}
	return 0;
}

int tamamd�r() 
{
	ofstream c�kt�;
	c�kt�.open("Schedule.txt");
	int bir = 0;
	int iki = 0;
	int time = 0;
	int firma = 0;
	int opcode = 0;
	int work = 0;
	int setup = 0;
	for (int x = 0; x < 200; x++)
	{
		for (int c = 0; c < 200; c++)
		{
			if (line[x].num != 0 && orders[c].num != 0)
			{
				if (line[x].num == orders[c].num)
				{
					if (time == 0)
					{
						setup = 0;
						firma = orders[c].which;
						opcode = orders[c].which;
						work = orders[c].amount;
						time = time + setup;
					}
					if (time != 0)
					{
						for (int d = 0; d < 1225; d++)
						{
							if (firma == setups[d].first)
							{
								if (orders[c].which == setups[d].second)
								{
									setup = setups[d].dur;
									firma = setups[d].second;
								}
							}
							if (firma == setups[d].second)
							{
								if (orders[c].which == setups[d].first)
								{
									setup = setups[d].dur;
									firma = setups[d].first;
								}
							}
						}
						opcode = orders[c].which;
						work = orders[c].amount;
						time = time + setup;
					}
					//
					c�kt� << time << "; " <<  opcode << "; " << orders[c].num << "; " << work << "; " << setup << endl;
					for (int u = 0; u < 50; u++)
					{
						if (ops[u].num == opcode)
						{
							if (work % ops[u].perm != 0)
							{
								bir = work / ops[u].perm;
								time = bir + 1 + time;
							}
							if (work % ops[u].perm == 0)
							{
								bir = work / ops[u].perm;
								time = bir + time;
							}
						}
					}
					setup = 0;
				}
			}
		}
	}
	return 0;
}

int main()
{
	ifstream girdi;
	string line;
	string sira;

	girdi.open("Operations.txt");
	while (getline(girdi, line))
	{
		operation(engel(line));
	}
	girdi.close();
	girdi.open("SetupDuration.txt");
	while (getline(girdi, sira))
	{
		setup(engel(sira));
	}
	girdi.close();
	girdi.open("Orders.txt");
	while (getline(girdi, sira))
	{
		order(engel(sira));
	}
	girdi.close();
	for (int x = 1; x < 50; x++)
	{
		priolister(x);
	}
	laster();
	boi�i(0);
	tamamd�r();
	return 0;
}