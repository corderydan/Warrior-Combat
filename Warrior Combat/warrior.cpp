#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"warrior.h"
#include<cstdlib>

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
warrior::warrior(int d)
{
   //some kind of difficulty sacle d so that competitors can be scale according to difficulty
}

bool combat(warrior& a,warrior& b)
{
    int a_damage, b_damage;
        while(a.get_health()>0&&b.get_health())
        {
            a_damage = rand() % (a.get_max_damage() - a.get_min_damage())+a.get_min_damage();
            b_damage = rand() % (b.get_max_damage() - b.get_min_damage())+b.get_min_damage();
            a.set_health(a.get_health()-b_damage);
            b.set_health(b.get_health()-a_damage);
        }
     bool temp;
     temp = (a.get_health()<b.get_health()); // must sort out better way for choosing winner
     return(temp);
}
bool aud_combat(warrior& a,warrior& b)
{

}

