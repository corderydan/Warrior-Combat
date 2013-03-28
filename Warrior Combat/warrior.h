#ifndef WARRIOR_H_INCLUDED
#define WARRIOR_H_INCLUDED

#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class warrior
{
private:
    int health;
    int max_damage;
    int min_damage;
    int recovery_rate;
    string name;
public:
    //the gets
    vector<int> get_atts();
    string get_name();
    int get_health();
    int get_max_damage();
    int get_min_damage();
    int get_recovery_rate();

    //the sets
    void set_health(int);
    void set_max_damage(int);
    void set_min_damage(int);
    void set_recovery_rate(int);

    //constructors
    warrior(int,int,int,int,string);
    warrior(int);
};

bool combat(warrior,warrior);
void winner_announce(warrior,warrior,bool);
bool audiblecombat (warrior,warrior);
vector<string> read_names();
int uniform_int_rand(int,int,int);


#endif // WARRIOR_H_INCLUDED
