#define PODPUNKT 3

#include <string>
#include <iostream>
#include "src/Order.h"
#include "src/OrdersCollection.h"

using namespace std;

int main () {
	Order z1("Bagietka", .99, 15, 20160812);
	Order z2("Bułka", 0.50, 50);

#if PODPUNKT == 2
	z1.print();
	z2.print();
#endif


#if PODPUNKT == 3
	OrdersCollection collection;

	collection.addOrder(z1);
	collection.addOrder(z2);
	collection.addOrder(Order("Chałka", 3.50, 10, 3));
	collection.addOrder(Order("Chałka", 3.50, 20, 3));
	collection.addOrder(Order("Bagietka", .99, 5, 5));
	collection.print();

	cout << "Suma zamówień na bagietki:  " << collection.getProductOrdersSum("Bagietka") << endl;
	cout << "Suma zamówień w miesiącu 3: " << collection.getProductOrdersInMonth(3) << endl;
	cout << "Najpopularniejszy produkt:  " << collection.mostPopularProduct() << endl;

#endif
}