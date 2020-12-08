#include <iostream>

using namespace std;

void drawSpaces(int spacesAmount) {
    for (int columns = 0; columns < spacesAmount; columns++)
        cout << " ";
}

void drawStars(int starsAmount) {
    for (int columns = 0; columns < starsAmount; columns++)
        cout << "*";
}

void drawTreeBody(int treeSize) {
    for (int rows = 0; rows < treeSize; rows++) {
        drawSpaces(treeSize-rows);
        drawStars(rows * 2 + 1);
        cout << endl;
    }
}

void drawStump(int treeSize) {
    drawSpaces(treeSize);
    cout << "*";
}

void drawChristmasTree(int treeSize) {
    drawTreeBody(treeSize);
    drawStump(treeSize);
}

int getUserInput() {
    int userInput;
    cout << "Enter tree size: ";
    cin >> userInput;
    return userInput;
}

int main()
{
    drawChristmasTree(getUserInput());
    return 0;
}
