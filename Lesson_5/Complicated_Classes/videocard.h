#ifndef VIDEOCARD_H
#define VIDEOCARD_H

#include <string>
#include <iostream>

using namespace std;

class videocard
{
public:
    videocard();

    void setName(string newName) { name = newName; }
    string getName() { return name; }

    void setSeries(string newSeries) { series = newSeries; }
    string getSeries() { return series; }

    void setPrice(double newPrice);
    double getPrice() { return price; }

private:
    string name;
    string series;
    double price;
};

#endif // VIDEOCARD_H
