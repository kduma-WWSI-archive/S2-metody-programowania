#include <iostream>

using namespace std;

long long silnia(int n)
{
	static int k = 0;
	k++;
	cout << "Wywolanie numer " << k << " dla n = " << n << endl;

	if (n == 0)
		return 1;
	else if (n > 0)
		return n * silnia(n - 1);

	return 666; // szatańska liczba :)
}

int main () {
	int n;
	cout << "Podaj n: ";
	cin >> n;
	long long w;
	w = silnia(n);
	cout << "Wynik (silnia): ";
	cout << w;
	cout << endl;
}