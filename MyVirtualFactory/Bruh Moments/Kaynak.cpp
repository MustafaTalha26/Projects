//////////////////////////////////////////
// Mustafa Talha MERT
// 1306200015
// Date: 2021.05.26
// IDE: Visual Studio 2019
///////////////////////////////////////////
// Operasyon sýnýrým 50.
// Setupdur sýnýrým 50.
// Order sýnýrým 200.
// Fonksiyonun üstündeki açýklamalar fonksiyon hakkýnda basit bilgiler verir.
// Yöntemim ayný deadline sürelerine sahip orderlarý bir sepete atmak ile baþlar.
// Orderý gerçekleþtirecek operasyon kendisine ait öncelik listesinden sepette var olan en yüksek öncelikli orderý seçer.
// Eleman sepetten silinir ve elemaný gerçekleþtirecek operasyon bir sonraki iþlem için devam eder.
// Sepette order kalmazsa bir sonraki deadline'a ait orderler sepete konur ve sýralanmamýþ hiçbir order kalmayýncaya kadar devam eder.
// Amaç operasyon geçiþlerinde en düþük süreli geçiþ iþlemlerini yakalayarak süreden yüksek oranda kar etmektir.
// Bilgisayar performansýna zarar vermemesi ve vakit çalmamasý amacýyla structure boyutlarýný düþük tuttum ama 
// istenildiði taktirde bu boyutlar algoritmaya hasar vermeden büyütülebilir.(1 milyon sipariþ hatrý sayýlýr miktarda süre alýyor.) 
//////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
string::size_type sz;

//okuyucu makine geçiþ
struct operasyon 
{
	int num = 0;
	int perm = 0;
}ops[50];

//okuyucu makineler arasý geçiþ
struct setuptime
{
	int first = 0;
	int second = 0;
	int dur = 0;
}setups[1225];

//okuyucu sipariþler
struct sp
{
	int num = 0;
	int amount = 0;
	int which = 0;
	int last = 0;
}orders[200];

//sipariþleri sýraladýðým liste
struct lin
{
	int num = 0;
	int last = 0;
	int opss = 0;
}line[200];

//makine geçiþleri öncelik listesi
struct priolist
{
	int one = 0;
	int arr[50] = {0};
}prio[50];

//sipraiþ vakitlerine göre ayýrýp bunun içinde sakladým
struct tarih
{
	int last = 0;
	int items[50] = { 0 };
}bo[50];

//isminden ötürü özür dilerim :D geçici sepet olarak kullandým
struct banakafayýyedirmedenöncekisonliste
{
	int ab = 0;
}avi[50];

//yardýmcý boþluk silen
string engel(string dirsek)
{
	int counter = 0;
	string yenisatýr = "";
	while (counter < dirsek.length())
	{
		if (dirsek.at(counter) != ' ')
		{
			yenisatýr += dirsek.at(counter);
		}
		counter++;
	}
	return yenisatýr;
}

//makine iþlemi okuyucu
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

//makine geçiþleri okuyucu
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

//sipariþ dosyasý okuyucu
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

//makine tak çýkar öncelik hesabý
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

//okuyucularýn düzgün çalýþtýðýný kontrol etmek için
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

//ayný süreye göre 
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

//sonraki algoritma iþlemleri için kullandýðým kontrol fonksiyonu
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

//en son bütün iþlemler bittikten sonra elimdeki liste
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

//üstünde çok uðraþtýðým fonksiyon
//Ayný deadline tarihindeki sipariþleri sepete koyar. Sepet boþalana kadar bir önceki sipraiþin çalýþtýðý makinenin öncelik ->
//listesindeki en yüksek öncelikli elemaný sepetten bulur ve listenin içine yazar. Yazýlan eleman sepetten silinir.
//Sepet boþalýnca bir sonraki tarihin elemanlarýný koyar ve bu iþlem sipariþ kalmayýncaya kadar devam eder.
//Amaç makine kurulum vakitlerinde zaman tasarrufu etmektir. Ýstenilen sonuç çýkmazsa algoritmanýn sýnýrlar yüzünden olabilir.
int global = 0;
int mist = -1;
int boiçi(int ilk = 0)
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
	//dünkü ben diyor ki orderlarý nasýl kontrol ediyorsun yani 
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
											boiçi(gecici);
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

int tamamdýr() 
{
	ofstream cýktý;
	cýktý.open("Schedule.txt");
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
					cýktý << time << "; " <<  opcode << "; " << orders[c].num << "; " << work << "; " << setup << endl;
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
	boiçi(0);
	tamamdýr();
	return 0;
}