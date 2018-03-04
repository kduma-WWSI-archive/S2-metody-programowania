#include <iostream>

using namespace std;

int main () {
	int a = 10, b = 11, c = 12;
	int *wsk = 0;

	cout << "Adres zmiennej a = " << &a << endl;
	cout << "Wartość zmiennej a = " << a << endl;
	cout << "Adres zmiennej b = " << &b << endl;
	cout << "Wartość zmiennej b = " << b << endl;
	cout << "Adres zmiennej c = " << &c << endl;
	cout << "Wartość zmiennej c = " << c << endl;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;

	wsk = &a;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;

	*wsk += 10;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;

	wsk = &b;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;

	*wsk += 11;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;

	wsk = &c;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;

	*wsk += 12;

	cout << "Wartość wskaźnika wsk = " << wsk << endl;
	cout << "Wartość wskazywanej zmiennej przez wsk = " << *wsk << endl;


	cout << "Adres zmiennej a = " << &a << endl;
	cout << "Wartość zmiennej a = " << a << endl;
	cout << "Adres zmiennej b = " << &b << endl;
	cout << "Wartość zmiennej b = " << b << endl;
	cout << "Adres zmiennej c = " << &c << endl;
	cout << "Wartość zmiennej c = " << c << endl;
}