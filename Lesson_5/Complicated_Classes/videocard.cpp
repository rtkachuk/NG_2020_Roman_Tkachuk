#include "videocard.h"

videocard::videocard()
{
    setName("NONAME");
    setPrice(0);
    setSeries("VOODOO 2");
}

void videocard::setPrice(double newPrice)
{
    if (newPrice < 0) {
        cout << "Error! Price can not be lower that 0! Price set to 0!" << endl;
        price = 0;
    } else {
        price = newPrice;
    }
}
