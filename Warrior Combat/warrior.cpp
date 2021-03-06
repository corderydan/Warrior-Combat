#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"warrior.h"
#include<cstdlib>
#include<ctime>

using namespace std;

string warrior::get_name()
{
    string temp;
    temp = name;
    return(temp);
}

vector<int> warrior::get_atts()
{
    vector<int> temp(4);
    temp[0] = health;
    temp[1] =max_damage;
    temp[2] =min_damage;
    temp[3] =recovery_rate;
    return(temp);
}

int warrior::get_health()
{
    return(health);
}
int warrior::get_max_damage()
{
    return(max_damage);
}
int warrior::get_min_damage()
{
    return(min_damage);
}
int warrior::get_recovery_rate()
{
    return(recovery_rate);
}

void warrior::set_health(int x)
{
    health=x;
}
void warrior::set_max_damage(int x)
{
    max_damage=x;
}
void warrior::set_min_damage(int x)
{
    min_damage=x;
}
void warrior::set_recovery_rate(int x)
{
    recovery_rate=x;
}

warrior::warrior(int x,int y,int z,int w,string s)
{
    health = x;
    max_damage = y;
    min_damage = z;
    recovery_rate = w;
    name = s;
}


bool combat(warrior a,warrior b)
{
    int a_damage, b_damage;
    int a_health = a.get_health();
    int b_health = b.get_health();
        while((a_health>0)&&(b_health>0))
        {
            a_damage = rand() % (a.get_max_damage() - a.get_min_damage())+a.get_min_damage();
            b_damage = rand() % (b.get_max_damage() - b.get_min_damage())+b.get_min_damage();
            a_health-=b_damage;
            b_health-=a_damage;
        }
     bool temp;
     temp = (a_health<b_health); // must sort out better way for choosing winner
     return(not(temp));
}

bool audiblecombat (warrior a,warrior b)
{
    srand (time(NULL));
    int a_damage, b_damage;
    int a_health = a.get_health();
    int b_health = b.get_health();
    int counter=1;
        while((a_health>0)&&(b_health>0))
        {
            a_damage = rand() % (a.get_max_damage() - a.get_min_damage())+a.get_min_damage();
            b_damage = rand() % (b.get_max_damage() - b.get_min_damage())+b.get_min_damage();
            a_health-=b_damage;
            b_health-=a_damage;
            cout << "Round " << counter << ":\n" << a.get_name() << " hit " << a_damage << " points. \n" <<
            b.get_name() << " hit " << b_damage << " points. \n" << a.get_name() << " health: " << a_health<<" " << b.get_name()<<
            " health: " << b_health << ".\n";
            counter++;

        }
     bool temp;
     temp = (a_health<b_health); // must sort out better way for choosing winner
     return(not(temp));
}

void winner_announce(warrior a,warrior b,bool d)
{
    if(d)
        {
                cout << a.get_name() <<" won\n";
        }
        else
        {
            cout<< b.get_name() <<" won\n";
        }
}

warrior::warrior(int x)
{
    vector<string> names = read_names();
    srand (time(NULL));
    int number = rand() % names.size();
    name= names[number];


}

vector<string> read_names()
{
    ifstream file("Names.dat");
    string temp;
    vector<string> name_array;
    while(file.good())
    {
        getline(file,temp);
        name_array.push_back(temp);
    }
    return(name_array);
}

int uniform_int_rand(int x,int y,int rando)
{
    srand(rando);
    int sum = 0,result = 0, temp;
    for(int i =0;i<20;i++)
    {
        temp= rand() % (y*2+1) +(x-y);
        sum+=temp;
    }
    result=(1.0*sum)/20;
    return(result);
}


