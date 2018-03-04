#ifndef ZADANIE_1_ORDER_H
#define ZADANIE_1_ORDER_H

#include <string>
#include <iostream>

class Order {
private:
	std::string name;
	double price;
	int quanity;
	int timestamp;
public:
	Order ( std::string name, double price, int quanity, int timestamp );

	Order ( std::string name, double price, int quanity );

	Order ();

	std::string getName ();

	double getPrice ();

	int getQuanity ();

	int getTimestamp ();

	double getCost ();

	void setData ( std::string name, double price, int quanity, int timestamp );

	void print ();
};


#endif //ZADANIE_1_ORDER_H
