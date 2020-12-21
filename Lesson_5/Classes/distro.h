#include <iostream>

using namespace std;

class Distro
{
public:
    Distro();

    int getScore() { return score; };
    void setScore(int value) { score = value; };

    void setName(string value) { name = value; };
    string getName() { return name; };

    void setComments(string value) { comments = value; };
    string getComments() { return comments; };

    void setFamily(string value) { family = value; };
    string getFamily() { return family; };

private:
    string name;
    string comments;
    string family;

    int score = 0;
};

