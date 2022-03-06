// Mustafa Talha MERT
// Date: 13.01.2021
// Development Environment: Visual Studio2019

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
string::size_type sz;

//I would like to say.
//I basicly used only those headers.
//What this code contains it is whole lot of string manipulation.
//To make spslll, spsl, spsr, spsrrr took lot of time.(I changed them a lot)
//main() function lowest part.
//Code itself is nearly 1000 lines because I reject using "if" and "for" in a reasonable way.
//The method I use is taking parts of line and throwing to start so there is nothing undone when it finished.(prob).
//My parentheses method is creating a new problemsolver function but only uses av[100].ismi av[100].cismi.
//Operator precedence method is using lined (for loops) so I can choose what will done first.
//My code can not do negatif numbers like -6 but it can do 8-2.
//I did not add "double" type of constant just because complexity will double up. And I used "to_string" rather than lexical_cast
//I did not add "==" it breaks code multiple ways. I did not add "!" bacause I did not understand how to use it.
//My code can do 1, 3, 5, 6, 7, 8, 9, 10 challanges. 
//And sorry for unusual integer/string names. I was out of ideas while I writing them.
//And thank you for reading this.

//stores variables.
struct variable
{
	string ismi = "ð";
	int cismi = 0;
} av[101];
//deletes empty spaces.
string engel(string dirsek)
{
	int counter = 0;
	string yenisatýr = "";
	while (counter < dirsek.length())
	{
		if (dirsek[counter] != ' ')
		{
			yenisatýr += dirsek[counter];
		}
		counter++;
	}
	return yenisatýr;
}
//detects right side's variable or constant and gives it's value.
int spsr(string txt)
{
	int kek = 0;
	int honk = 0;
	string sayi = "123456789";
	string strike = "";
	string wall = "/*+-";
	int s = 0;
	string::size_type sz;
	for (int x = 0; x < txt.length(); x++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (txt.at(x) == wall.at(c))
			{
				kek = x;
			}
		}
		if (kek != 0)
		{
			break;
		}
	}
	if (kek == 0)
	{
		strike = txt;
		for (int c = 0; c < 9; c++)
		{
			if (strike.at(0) == sayi.at(c))
			{
				honk = 1;
			}
		}
		if (honk == 1)
		{
			s = stoi(strike, &sz);
			return s;
		}
		if (honk == 0)
		{
			for (int z = 0; z < 100; z++)
			{
				if (strike == av[z].ismi)
				{
					s = av[z].cismi;
				}
			}
			return s;
		}
	}
	if (kek != 0)
	{
		for (int x = 0; x < kek; x++)
		{
			strike = strike + txt.at(x);
		}
		for (int c = 0; c < 9; c++)
		{
			if (strike.at(0) == sayi.at(c))
			{
				honk = 1;
			}
		}
		if (honk == 1)
		{
			s = stoi(strike, &sz);
			return s;
		}
		if (honk == 0)
		{
			for (int z = 0; z < 100; z++)
			{
				if (strike == av[z].ismi)
				{
					s = av[z].cismi;
				}
			}
			return s;
		}
	}
	return 0;
}
//detects left side's variable or constant and gives it's value.
int spsl(string txt)
{
	int honk = 0;
	string sayi = "123456789";
	string strike = "";
	string wall = "/*+-";
	int s = 0;
	int kek = 0;
	string::size_type sz;

	for (int x = 0; x < txt.length(); x++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (txt.at(x) == wall.at(c))
			{
				kek = x;
			}
		}
	}
	if (kek == 0)
	{
		strike = txt;
		for (int c = 0; c < 9; c++)
		{
			if (txt.at(0) == sayi.at(c))
			{
				honk = 1;
			}
		}
		if (honk == 1)
		{
			s = stoi(strike, &sz);
			return s;
		}
		if (honk == 0)
		{
			if (honk == 0)
			{
				for (int z = 0; z < 100; z++)
				{
					if (strike == av[z].ismi)
					{
						s = av[z].cismi;
					}
				}
				return s;
			}
		}
	}
	if (kek != 0)
	{
		for (int x = kek + 1; x < txt.length(); x++)
		{
			strike = strike + txt.at(x);
		}
		for (int c = 0; c < 9; c++)
		{
			if (strike.at(0) == sayi.at(c))
			{
				honk = 1;
			}
		}
		if (honk == 1)
		{
			s = stoi(strike, &sz);
			return s;
		}
		if (honk == 0)
		{
			for (int z = 0; z < 100; z++)
			{
				if (strike == av[z].ismi)
				{
					s = av[z].cismi;
				}
			}
			return s;
		}
	}
	return 0;
}
//does the < > <= >=
int trooper(string sat)
{
	string right = "";
	string left = "";
	int trooper = 0;
	int lack = 0;
	int clack = 0;
	int kimkim = 0;
	int tim = 0;
	int ta = 0;
	for (int x = 0; x < sat.length(); x++)
	{
		if (sat.at(x) == '<')
		{
			lack = x;
			kimkim = 1;
			if (sat.at(x + 1) == '=')
			{
				clack = x + 1;
				tim = 1;
			}
			else
			{
				clack = x;
				tim = 0;
			}
		}
		if (sat.at(x) == '>')
		{
			lack = x;
			kimkim = 0;
			if (sat.at(x + 1) == '=')
			{
				clack = x + 1;
				tim = 1;
			}
			else
			{
				clack = x;
				tim = 0;
			}
		}
		if (sat.at(x) == '!')
		{
			clack = x + 1;
			lack = x;
			ta = 1;
		}
	}
	for (int x = 0; x < lack; x++)
	{
		left = left + sat.at(x);
	}
	for (int x = clack+1; x < sat.length(); x++)
	{
		right = right + sat.at(x);
	}
	if (kimkim == 1 && tim == 1)
	{
		if (spsl(left) <= spsr(right))
		{
			return 1;
		}
	}
	if (kimkim == 1 && tim == 0)
	{
		if (spsl(left) < spsr(right))
		{
			return 1;
		}
	}
	if (kimkim == 0 && tim == 1)
	{
		if (spsl(left) >= spsr(right))
		{
			return 1;
		}
	}
	if (kimkim == 0 && tim == 0)
	{
		if (spsl(left) > spsr(right))
		{
			return 1;
		}
	}
	if (ta == 1)
	{
		if (spsl(left) != spsr(right))
		{
			return 1;
		}
	}
	return 0;
}
//detects a op string like "/*-+" in right. It is spsr's right string. I am using this with spsr. 
string spsrrr(string txt)
{
	int kek = 0;
	int honk = 0;
	string sayi = "123456789";
	string strike = "";
	string wall = "/*+-";
	int s = 0;
	for (int x = 0; x < txt.length(); x++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (txt.at(x) == wall.at(c))
			{
				kek = x;
			}
		}
		if (kek != 0)
		{
			break;
		}
	}
	if (kek == 0)
	{
		return "";
	}
	for (int x = kek; x < txt.length(); x++)
	{
		strike = strike + txt.at(x);
	}
	return strike;
}
//detects a op string like "/*-+" in right. It is spsr's left string. I am using this with spsl.
string spslll(string txt)
{
	int honk = 0;
	string sayi = "123456789";
	string strike = "";
	string wall = "/*+-";
	int s = 0;
	int kek = 0;

	for (int x = 0; x < txt.length(); x++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (txt.at(x) == wall.at(c))
			{
				kek = x;
			}
		}
	}
	if (kek == 0)
	{
		return "";
	}
	for (int x = 0; x < kek+1; x++)
	{
		strike = strike + txt.at(x);
	}
	return strike;
}
//it helps me for string manipulation
string midlaner(string sol, string mid, string sag)
{
	return(sol + mid + sag);
}
//prob of par is for parentheses. It basicly does math.
string probofpar(string sat)
{
	unsigned int zaman = sat.length();
	string sayi = "123456789";
	string wall = "/*+-";
	string left = "";
	string right = "";
	string fin = "";
	string gura = "";
	string gurr = "";
	string gull = "";
	int doespar = 0;
	int parantl = 0;
	int parantr = 0;
	int trunk = 0;
	int finland = 0;
	int first = 0;
	int second = 0;
	int xx = 0;
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '=')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			av[100].ismi = left;
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			for (int x = 0; x < right.length(); x++)
			{
				for (int c = 0; c < 4; c++)
				{
					if (right.at(x) == wall.at(c))
					{
						trunk = 1;
					}
				}
			}
			if (trunk == 1)
			{
				return (probofpar(right));
			}
			for (int c = 0; c < 9; c++)
			{
				if (right.at(0) == sayi.at(c))
				{
					xx = stoi(right, &sz);
					av[100].cismi = xx;
				}
			}
			return (probofpar(right));
		}
	}
	//=
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '*')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first * second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[100].ismi + "=" + fin;
			return(probofpar(fin));
		}
		if (sat.at(x) == '/')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first / second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[100].ismi + "=" + fin;
			return(probofpar(fin));
		}
	}
	//* /
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '+')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first + second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[100].ismi + "=" + fin;
			return(probofpar(fin));
		}
		if (sat.at(x) == '-')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first - second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[100].ismi + "=" + fin;
			return(probofpar(fin));
		}
	}
	//+ -
	return "";
}
//this locker integer is for passing through variables that I struct. It is in main(). 
int locker = 0;
//for the out case.
int nummm = 0;
//this is my actual function. It has detection of keywords and operations. And it does a lot math.
string prob(string sat)
{
	unsigned int zaman = sat.length();
	string llbone = "";
	string ttbone = "";
	string henry = "";
	string sayi = "123456789";
	string wall = "/*+-";
	string left = "";
	string right = "";
	string fin = "";
	string gura = "";
	string gurr = "";
	string gull = "";
	string leftpar = "(";
	string rightpar = ")";
	string times = "*";
	int fork = 0;
	int rigged = 0;
	int lbone = 0;
	int l_bone = 0;
	int afterlbone = 0;
	int after_lbone = 0;
	int tbone = 0;
	int t_bone = 0;
	int aftertbone = 0;
	int after_tbone = 0;
	int crook = 0;
	int doespar = 0;
	int parantl = 0;
	int parantr = 0;
	int trunk = 0;
	int finland = 0;
	int first = 0;
	int second = 0;
	int xx = 0;
	int out = 0;
	//out case
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == 'O')
		{
			if (sat.at(x + 1) == 'U')
			{
				if (sat.at(x + 2) == 'T')
				{
					out = 1;
				}
			}
		}
	}
	if (out == 1)
	{
		string suspect = "";
		for (int x = 3; x < sat.length(); x++)
		{
			suspect = suspect + sat.at(x);
		}
		for (int z = 0; z < 100; z++)
		{
			if (suspect == av[z].ismi)
			{
				nummm = av[z].cismi;
			}
		}
	}
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(0) == 'L')
		{
			if (sat.at(1) == 'O')
			{
				if (sat.at(2) == 'O')
				{
					if (sat.at(3) == 'P')
					{
						for (int x = 4; x < sat.length(); x++)
						{
							right = right + sat.at(x);
						}
						return prob(right);
					}
				}
			}
		}
		if (sat.at(x) == 'T')
		{
			if (sat.at(x + 1) == 'I')
			{
				if (sat.at(x + 2) == 'M')
				{
					if (sat.at(x + 3) == 'E')
					{
						if (sat.at(x + 4) == 'S')
						{
							rigged = x;
							for (int x = 0; x < sat.length(); x++)
							{
								if (sat.at(x) == '=')
								{
									fork = x + 1;
								}
							}
							for (int x = 0; x < fork-1; x++)
							{
								left = left + sat.at(x);
							}
							av[locker].ismi = left;
							left = "";
							for (int x = fork; x < rigged; x++)
							{
								left = left + sat.at(x);
							}
							for (int x = rigged + 5; x < sat.length(); x++)
							{
								right = right + sat.at(x);
							}
							right = leftpar + left + rightpar + times + to_string(spsr(right));
							return (prob(av[locker].ismi + "=" + right));
						}
					}
				}
			}
		}
	}
	//loop
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '=')
		{
			if (sat.at(x - 1) == '<')
			{
				crook = 1;
			}
			if (sat.at(x - 1) == '>')
			{
				crook = 1;
			}
			if (sat.at(x - 1) == '!')
			{
				crook = 1;
			}
			if (crook == 0)
			{
				for (int c = 0; c < x; c++)
				{
					left = left + sat.at(c);
				}
				av[locker].ismi = left;
				for (int z = x + 1; z < sat.length(); z++)
				{
					right = right + sat.at(z);
				}
				cout << right << endl;
				for (int x = 0; x < right.length(); x++)
				{
					for (int c = 0; c < 4; c++)
					{
						if (right.at(x) == wall.at(c))
						{
							trunk = 1;
						}
					}
				}
				if (trunk == 1)
				{
					return (prob(right));
				}
				for (int c = 0; c < 9; c++)
				{
					if (right.at(0) == sayi.at(c))
					{
						xx = stoi(right, &sz);
						av[locker].cismi = xx;
					}
				}
				return (prob(right));
			}
			if (crook == 1)
			{
				for (int x = 0; x < sat.length(); x++)
				{
					if (sat.at(x) == leftpar.at(0))
					{
						parantl = x;
						doespar = 1;
					}
					if (sat.at(x) == rightpar.at(0))
					{
						parantr = x;
					}
				}
				if (doespar == 1)
				{
					for (int c = 0; c < parantl; c++)
					{
						gull = gull + sat.at(c);
					}
					for (int c = parantl + 1; c < parantr; c++)
					{
						gura = gura + sat.at(c);
					}
					for (int c = parantr + 1; c < sat.length(); c++)
					{
						gurr = gurr + sat.at(c);
					}
					av[100].ismi = "X";
					gura = av[100].ismi + "=" + gura;
					probofpar(gura);
					gura = to_string(av[100].cismi);
					cout << gull << gura << gurr << endl;
					return prob(gull + gura + gurr);
				}
				if (doespar == 0)
				{
					for (int x = 0; x < sat.length(); x++)
					{
						if (sat.at(x) == 'T')
						{
							if (sat.at(x + 1) == 'H')
							{
								if (sat.at(x + 2) == 'E')
								{
									if (sat.at(x + 3) == 'N')
									{
										tbone = x;
										aftertbone = x + 3;
									}
								}
							}
						}
						t_bone = tbone;
						after_tbone = aftertbone;
						if (sat.at(x) == 'E')
						{
							if (sat.at(x + 1) == 'L')
							{
								if (sat.at(x + 2) == 'S')
								{
									if (sat.at(x + 3) == 'E')
									{
										lbone = x + 3;
										afterlbone = x;
									}
								}
							}
						}
						after_lbone = afterlbone;
						l_bone = lbone;
					}
					for (int x = after_tbone + 1; x < after_lbone; x++)
					{
						ttbone = ttbone + sat.at(x);
					}
					for (int x = l_bone + 1; x < sat.length(); x++)
					{
						llbone = llbone + sat.at(x);
					}
					for (int x = 2; x < tbone; x++)
					{
						henry = henry + sat.at(x);
					}
					if (trooper(henry) == 1)
					{
						av[locker].cismi = spsr(ttbone);
					}
					if (trooper(henry) == 0)
					{
						av[locker].cismi = spsr(llbone);
					}
					return "";
				}
			}
		}
		if (sat.at(x) == '<')
		{
			crook = 1;
		}
		if (sat.at(x) == '>')
		{
			crook = 1;
		}
		if (crook == 1)
		{
			for (int x = 0; x < sat.length(); x++)
			{
				if (sat.at(x) == leftpar.at(0))
				{
					parantl = x;
					doespar = 1;
				}
				if (sat.at(x) == rightpar.at(0))
				{
					parantr = x;
				}
			}
			if (doespar == 1)
			{
				for (int c = 0; c < parantl; c++)
				{
					gull = gull + sat.at(c);
				}
				for (int c = parantl + 1; c < parantr; c++)
				{
					gura = gura + sat.at(c);
				}
				for (int c = parantr + 1; c < sat.length(); c++)
				{
					gurr = gurr + sat.at(c);
				}
				av[100].ismi = "X";
				gura = av[100].ismi + "=" + gura;
				probofpar(gura);
				gura = to_string(av[100].cismi);
				return prob(gull + gura + gurr);
			}
			if (doespar == 0)
			{
				for (int x = 0; x < sat.length(); x++)
				{
					if (sat.at(x) == 'T')
					{
						if (sat.at(x + 1) == 'H')
						{
							if (sat.at(x + 2) == 'E')
							{
								if (sat.at(x + 3) == 'N')
								{
									tbone = x;
									aftertbone = x + 3;
								}
							}
						}
					}
					t_bone = tbone;
					after_tbone = aftertbone;
					if (sat.at(x) == 'E')
					{
						if (sat.at(x + 1) == 'L')
						{
							if (sat.at(x + 2) == 'S')
							{
								if (sat.at(x + 3) == 'E')
								{
									lbone = x + 3;
									afterlbone = x;
								}
							}
						}
					}
					after_lbone = afterlbone;
					l_bone = lbone;
				}
				for (int x = after_tbone + 1; x < after_lbone; x++)
				{
					ttbone = ttbone + sat.at(x);
				}
				for (int x = l_bone + 1; x < sat.length(); x++)
				{
					llbone = llbone + sat.at(x);
				}
				for (int x = 2; x < tbone; x++)
				{
					henry = henry + sat.at(x);
				}
				if (trooper(henry) == 1)
				{
					av[locker].cismi = spsr(ttbone);
				}
				if (trooper(henry) == 0)
				{
					av[locker].cismi = spsr(llbone);
				}
				return "";
			}
		}
	}
	//=
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == leftpar.at(0))
		{
			parantl = x;
			doespar = 1;
		}
		if (sat.at(x) == rightpar.at(0))
		{
			parantr = x;
		}
	}
	//checks par
	if (doespar == 1)
	{
		for (int c = 0; c < parantl; c++)
		{
			gull = gull + sat.at(c);
		}
		for (int c = parantl+1; c < parantr; c++)
		{
			gura = gura + sat.at(c);
		}
		for (int c = parantr + 1; c <sat.length(); c++)
		{
			gurr = gurr + sat.at(c);
		}
		av[100].ismi = "X";
		gura = av[100].ismi + "=" + gura;
		probofpar(gura);
		gura = to_string(av[100].cismi);
		return prob(gull + gura + gurr);
	}
	//divide par
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '*')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first * second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[locker].ismi + "=" + fin;
			return(prob(fin));
		}
		if (sat.at(x) == '/')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first / second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[locker].ismi + "=" + fin;
			return(prob(fin));
		}
	}
	//* /
	for (int x = 0; x < zaman; ++x)
	{
		if (sat.at(x) == '+')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first + second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[locker].ismi + "=" + fin;
			return(prob(fin));
		}
		if (sat.at(x) == '-')
		{
			for (int c = 0; c < x; c++)
			{
				left = left + sat.at(c);
			}
			for (int z = x + 1; z < sat.length(); z++)
			{
				right = right + sat.at(z);
			}
			first = spsl(left);
			second = spsr(right);
			x = first - second;
			fin = to_string(x);
			fin = midlaner(spslll(left), fin, spsrrr(right));
			fin = av[locker].ismi + "=" + fin;
			return(prob(fin));
		}
	}
	//+ -
	return "";
}
//clears between files
int clearmen()
{
	locker = 0;
	nummm = 0;
	for (int z = 0; z < 101; z++)
	{
		av[z].ismi = "ð";
		av[z].cismi = 0;
	}
	return 0;
}

int main()
{
	ifstream girdi;
	ofstream cýktý;
	string line;
	string edu;

	girdi.open("Challange1.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange1.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange2.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange2.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange3.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange3.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange4.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange4.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange5.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange5.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange6.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange6.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange7.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange7.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange8.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange8.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();

	girdi.open("Challange9.inp");
	while (getline(girdi, line))
	{
		edu = engel(line);
		prob(edu);
		locker++;
	}
	girdi.close();
	cýktý.open("Challange9.out");
	cýktý << nummm;
	cýktý.close();
	clearmen();
	return 0;
}
