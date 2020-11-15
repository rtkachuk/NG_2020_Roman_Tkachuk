#include <iostream>

using namespace std;

int main()
{
	int array[10];

	for (int i=0; i<10; i++) {
		array[i] = 0;
	}

	cout << "Введите пожалуйста 5-ый элемент массива: ";
	cin >> array[4];

	for (int i=0; i<10; i++) {
		cout << array[i] << endl;
	}
}
