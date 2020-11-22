#include <iostream>

using namespace std;

int main()
{
    char stroka[10]; // Here are we created char array
    cout << "Enter stroku: ";
    cin.getline(stroka, 10);  // Here we filled it with data
    int i=0;
    while (stroka[i]!=0) {  // At the end of user data 0 placed
        int chtoEto = stroka[i]; // Get character code
        cout << chtoEto << ":::" << stroka[i] << endl; // show it on the display
        i++;
    }
}
