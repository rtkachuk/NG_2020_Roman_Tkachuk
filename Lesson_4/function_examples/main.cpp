#include <iostream>

using namespace std;

void show(int a[], int size) {
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void process(int a[], int size) {
    for (int i=0; i<size; i++) {
        a[i] = i;
    }
}

void drawLine(int size) {
    if (size > 1) {
        drawLine(size - 1);
    }
    cout << "*";
}

void drawPyromid(int size) {
    drawLine(size);
    cout << endl;
    if (size > 1)
        drawPyromid(size-1);
    drawLine(size);
    cout << endl;
}

int main()
{
    // Example with arrays
    //

    int a[10];
    for (int i=0; i<10; i++) {
        a[i] = 0;
    }
    cout << a << endl; // Small tip :3

    process(a, 10);
    show(a, 10);

    // Draw pyromid
    // .... without cycles
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    drawPyromid(5);

    cout << endl;
    cout << endl;
}
