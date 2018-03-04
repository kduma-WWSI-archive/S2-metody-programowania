#ifndef ZADANIE_1_ORDERSCOLLECTION_H
#define ZADANIE_1_ORDERSCOLLECTION_H


#include <iosfwd>
#include <vector>
#include "Order.h"

class OrdersCollection {
public:
	std::vector<Order> Orders;

	OrdersCollection ();

	void addOrder(Order order);

	void print ();

	double getProductOrdersSum(std::string name);

	double getProductOrdersInMonth(int month);

	std::string mostPopularProduct ();
};


#endif //ZADANIE_1_ORDERSCOLLECTION_H
