#include <iostream>
#include"warrior.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    warrior one(550,10,1,7,"Warrior A");
    warrior two(550,10,1,7,"Warrior B");
    for(int i=0;i<15;i++)
    {
        winner_announce(one,two,combat(one,two));
    }

    return 0;
}
