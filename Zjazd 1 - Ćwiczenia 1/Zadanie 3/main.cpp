#include <iostream>

using namespace std;

int nwd(int x, int y){
	static int k = 0;
	k++;
	cout << "Wywolanie numer " << k << " dla x = " << x << " i y = " << y << endl;

	if (x%y)
		return nwd(y, x%y);
	return y;
}

int main () {
	int x, y;
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj y: ";
	cin >> y;
	int w;
	w = nwd(x, y);
	cout << "Wynik (nwd): ";
	cout << w;
	cout << endl;
}