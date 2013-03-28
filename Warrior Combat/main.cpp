#include <iostream>
#include"warrior.h"

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

    return 0;
}
