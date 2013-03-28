#include <iostream>
#include"warrior.h"
#include<ctime>
#include<cstdlib>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    warrior one(40,10,1,7,"Warrior A");
    warrior two(40,10,1,7,"Warrior B");
    for(int i=0;i<1;i++)
    {
        winner_announce(one,two,audiblecombat(one,two));
    }

    srand(time(NULL));

    for (int i=0;i<20;i++)
    {

        cout << uniform_int_rand(20,30,rand())<< endl;
    }



    return 0;
}
