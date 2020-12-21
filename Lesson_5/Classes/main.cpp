#include <iostream>
#include "distro.h"

using namespace std;

int main()
{
    Distro ubuntu;
    ubuntu.setName("Ubuntu");

    cout << "Distro: " << ubuntu.getName() << endl;
    cout << "User score: " << ubuntu.getScore() << "/5" << endl;
    cout << "Family: " << ubuntu.getFamily() << endl;
    cout << "Comments: " << ubuntu.getComments() << endl;
}
