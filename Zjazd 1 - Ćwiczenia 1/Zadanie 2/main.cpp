#include <iostream>

using namespace std;

long long fibbonaci(int n)
{
	static int k = 0;
	k++;
	cout << "Wywolanie numer " << k << " dla n = " << n << endl;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	return fibbonaci(n - 1) + fibbonaci(n - 2);
}

long long fibbonaci_iter(int n)
{
	static int k = 0;

	int f0 = 0, f1 = 1, fn;

	if (n == 0)
		return f0;
	else if (n == 1)
		return f1;

	for(int i=2; i <= n; i++)
	{
		k++;
		cout << "Iteracja numer " << k << endl;

		fn = f1 + f0;
		f0 = f1;
		f1 = fn;
	}

	return fn;
}

int main () {
	int n;
	cout << "Podaj n: ";
	cin >> n;
	long long w;
	w = fibbonaci(n);
	cout << "Wynik (fibbonaci):       ";
	cout << w;
	cout << endl;
	w = fibbonaci_iter(n);
	cout << "Wynik (fibbonaci iter.): ";
	cout << w;
	cout << endl;
}