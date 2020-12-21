#include "videopicker.h"

videopicker::videopicker()
{

}

void videopicker::list_all()
{
    showCardsAmount();
    for (videocard temp : videocards)
    {
        cout << temp.getName() << "\t" << temp.getPrice() << "$" << endl;
    }
}

void videopicker::addVideocard(string name, string series, int price)
{
    videocard temp;
    temp.setName(name);
    temp.setSeries(series);
    temp.setPrice(price);

    addVideocard(temp);
}

void videopicker::addVideocard(videocard temp)
{
    videocards.push_back(temp);
}

void videopicker::delByName(string name)
{
    int current = 0;
    for (videocard temp : videocards) {
        if (temp.getName() == name) {
            videocards.erase(videocards.begin() + current);
        }
        current++;
    }
}

void videopicker::findCardLowerPrice(double price)
{
    showCardsAmount();
    for (videocard temp : videocards)
    {
        if (temp.getPrice() <= price)
            cout << temp.getName() << "\t" << temp.getPrice() << "$" << endl;
    }
}

void videopicker::showCardsAmount()
{
    cout << "There are " << videocards.size() << " videocards known" << endl;
}
