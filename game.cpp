#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;


#define Miss 20
#define Start_Hit 10
#define Hit_Magic_hp 15
#define Mana 50


bool fight_1 = true;
struct info
{
	int strenght;
	int agility;
	int stamina;
	int dodge; // óêëîíåíèå
	int hit;
	int hp;
	int energy;
};

class human
{
	info _info;
public:
	human ()
	{_info.hp = 100; _info.energy = 100; _info.hit = 10; _info.dodge = 20;}

	void Hit_hp(int hp)
	{_info.hp -= hp;}

	void Hit_Magic(int hp)
	{
		_info.hp -= hp;
	}

	void Energy_sub(int energy)
	{
		_info.energy-=energy;
	}

	void Set_Stats(int strenght, int agility, int stamina)
	{
		_info.strenght = strenght;
		_info.agility = agility;
		_info.stamina = stamina;
		Exchange_stats();
	}

	void Exchange_stats()
	{
		_info.hp +=_info.stamina*20;
		_info.hit +=_info.strenght*2;
		_info.dodge +=_info.agility*10;
	}

	int Energy()
	{return _info.energy;}
	int hp()
	{return _info.hp;}
	int Strenght()
	{return _info.strenght;}
	int Agility()
	{return _info.agility;}
	int Stamina()
	{return _info.stamina;}
	int Hit()
	{return _info.hit;}
	int Dodge()
	{return _info.dodge;}
};

void Set_points(int & point, int & points)
{
	while (true)
		{
			if (point > points)
			{ printf("You cannot chose more than %d points!\n", points);
			cout << "Enter another amount of points: ";
			  cin >> point;}
			else 
			{points -= point; break;}
		}
}

void print_end_of_chose ()
{
			cout << endl <<"=========================================="<<endl;
			cout << "You set your main stats!";
			cout << endl <<"=========================================="<<endl;
}
void choose_stats(human &data) {
	int points = 5;
	int Strenght = 0 , Agility = 0, Stamina = 0;
	cout << "\nChose amount of your main characteristics (Strenght, Agility, Stamina):" << endl;
	printf("You have %d points. \n", points);
	cout << "Strenght: "; cin >> Strenght;
	Set_points (Strenght, points);
		
	if (points != 0)
	{
		printf("You have %d points. \n", points);
		cout << "Agility: ";  cin >> Agility;
		Set_points (Agility, points);
	}
	if (points != 0)
	{
		printf("You have %d points. \n", points);
		cout << "Stamina: "; cin >> Stamina;
		Set_points (Stamina, points);
	}
	data.Set_Stats(Strenght, Agility, Stamina);
}

int main ()
{
	srand(time(0));
	int var;
	
	while(true) {
		cout << "1. Play.\n";
		cout << "2. Exit.\n";
		cout << ">>>>>>";
		cin >> var;
		switch (var) 
		{
			case 1: 
			{	
				human var1;
				human var2;
				
				choose_stats(var1);
				choose_stats(var2);
				print_player_stats(var1, var2);
	
				while(true)
				{
		
					if (var1.hp() <= 0)
					{
						cls();
						cout << endl <<"=========================================="<<endl;
						cout << "               !!!Player Two Win!!! ";
						cout << endl <<"=========================================="<<endl;
						break;
					}

					if (var2.hp() <= 0)
					{
						cls();
						cout << endl <<"=========================================="<<endl;
						cout << "               !!!Player One Win!!! ";
						cout << endl <<"=========================================="<<endl;
						break;
					}
					cout << "var1 :" << endl;
					cout << "hp = " << var1.hp() << "  " << "Energy = " << var1.Energy() << endl;

					cout << "var2 :" << endl;
					cout << "hp = " << var2.hp() << "  " << "Energy = " << var2.Energy() << endl;

					if (fight_1)
					{cout << "........First player turn............ "<< endl;}
					else
					{cout << "........Second player turn........... "<< endl;}
					//cin >> var;
					var = 1;
					switch(var)
					{
						case 1: 
						{
							//cls();
							if (fight_1)
							{
								fight_1 = !fight_1;
								if (rand() % 101 < var2.Dodge())
								{
									cout << endl <<"=========================================="<<endl;
									cout << "                MISS           ";
									cout << endl <<"=========================================="<<endl;
									break;
								}
								var2.Hit_hp(var1.Hit());
								cout << "\n       HIT : " << var1.Hit() << endl;
							}
							else 
							{	
								fight_1 = !fight_1;
								if (rand() % 101 < var1.Dodge())
								{
									cout << endl <<"=========================================="<<endl;
									cout << "                MISS           ";
									cout << endl <<"=========================================="<<endl;
									break;	
								}
								var1.Hit_hp(var2.Hit());
								cout << "\n       HIT : " << var2.Hit() << endl;
					    	}
						break;
						}
					}
				break;
			}
				case 2: 
				{
					return 0;
				}
		}
	}


	
	return 0;
}
