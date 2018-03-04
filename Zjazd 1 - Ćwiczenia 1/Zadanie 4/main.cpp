#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c){
	static int k = 0;
	static int r = 0;
	k++;

	if (n == 1){
		r++;
		cout << k << ": " << a << "->" << c << " (" << r << " ruchy)" << endl;
		return;
	}

	hanoi(n - 1, a, c, b);
	hanoi(1, a, b, c);
	hanoi(n - 1, b, a, c);
}

int main () {
	int n;
	cout << "Podaj n: ";
	cin >> n;

	hanoi(n, 'a', 'b', 'c');
}