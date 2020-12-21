#include <iostream>
#include "videopicker.h"

using namespace std;

int main()
{
    videopicker manager;

    manager.addVideocard("GTX 1660 Ti", "16", 230);
    manager.addVideocard("GTX 1050 Ti", "10", 160);
    manager.addVideocard("RTX 2050 Ti", "20", 300);

    manager.delByName("GTX 1660 Ti");

    manager.findCardLowerPrice(200);

    manager.list_all();

    return 0;
}
