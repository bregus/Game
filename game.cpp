#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;


#define MISS 20
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
	int critical;
	int critical_hit;
};

class human
{
	info _info;
public:
	human ()
	{_info.hp = 100; _info.energy = 100; _info.hit = 10; _info.dodge = MISS; _info.critical_hit=_info.hit; _info.critical = 2;}

	void Hit_hp(int hp)
	{_info.hp -= hp;}

	void Hit_hp_crit(int hp)
	{
		_info.hp -= hp;
	}

	void Hit_Magic(int hp)
	{
		_info.hp -= hp;
	}

	void Energy_sub(int energy)
	{
		_info.energy-=energy;
	}

	void ResetStatsAfterBattle() 
	{
		_info.hp = 100 + _info.stamina*20;
	}

	void Set_Stats(int strenght, int agility, int stamina, int critical)
	{
		_info.strenght = strenght;
		_info.agility = agility;
		_info.stamina = stamina;
		_info.critical += critical;
		Exchange_stats();
	}

	void Exchange_stats()
	{
		_info.hp +=_info.stamina*20;
		_info.hit +=_info.strenght*2;
		_info.dodge +=_info.agility*10;
		_info.critical_hit = _info.hit*(_info.critical);
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
	int Crit()
	{return _info.critical_hit;}
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
	int Strenght = 0 , Agility = 0, Stamina = 0, Critical=0;
	
	cout << "\nChose amount of your main characteristics (Strenght, Agility, Stamina, Critical Hit):" << endl;
	cout << "You have only 5 point for all main characteristics (Strenght, Agility, Stamina, Critical Hit)." << endl;
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
	if (points != 0)
	{
		printf("You have %d points. \n", points);
		cout << "Critical: "; cin >> Critical;
		Set_points (Critical, points);
	}
	data.Set_Stats(Strenght, Agility, Stamina,Critical);
}

void battleProcess(human & var1, human & var2)
{
	while(true)
				{
					if (var1.hp() <= 0)
					{
						
						cout << endl <<"=========================================="<<endl;
						cout << "               !!!Player Two Win!!! ";
						cout << endl <<"=========================================="<<endl;
						break;
					}

					if (var2.hp() <= 0)
					{
						
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
					
					int var;
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
								if (rand() % 100 < 50)
								{
									var2.Hit_hp_crit(var1.Crit());
									cout << "\n       CRIT : "<<var1.Crit() << endl; 
								}
								else{
									var2.Hit_hp(var1.Hit());
									cout << "\n       HIT : " << var1.Hit() << endl;
								}
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
								if (rand() % 100 < 50)
								{
									var1.Hit_hp_crit(var2.Crit());
									cout << "\n       CRIT : "<<var2.Crit() << endl; 
								}
								else
								{
									var1.Hit_hp(var2.Hit());
									cout << "\n       HIT : " << var2.Hit() << endl;
								}
					    	}
							break;
							}
					}
				}
}

int main ()
{
	srand(time(0));
	int var;
	human var1;
	human var2;

	while(true) {
		cout << "1. Play.\n";
		cout << "2. Repeat.\n";
		cout << "3. Exit.\n";
		cout << ">>_. ";
		cin >> var;

		switch (var) 
		{
			case 1: 
			{	
				
				
				choose_stats(var1);
				choose_stats(var2);
				
				battleProcess(var1,var2);

				
				break;
			}
			case 2:
			{
				var1.ResetStatsAfterBattle();
				var2.ResetStatsAfterBattle();
				battleProcess(var1,var2);
				break;
			}
			case 3: 
			{
				return 0;
			}
		}
	}
	return 0;
}