#include <string>
#include <iostream>

#include "Order.h"


void Order::setData ( std::string name, double price, int quanity, int timestamp ) {
	Order::name = name;
	Order::price = price;
	Order::quanity = quanity;
	Order::timestamp = timestamp;
}

Order::Order ( std::string name, double price, int quanity, int timestamp ) {
	setData(name, price, quanity, timestamp);
}

Order::Order ( std::string name, double price, int quanity ) {
	setData(name, price, quanity, 0);
}

Order::Order () {
	setData("", 0, 0, 0);
}

std::string Order::getName () {
	return name;
}

double Order::getPrice () {
	return price;
}

int Order::getQuanity () {
	return quanity;
}

int Order::getTimestamp () {
	return timestamp;
}

double Order::getCost () {
	return price * quanity;
}

void Order::print () {
	std::cout << "===========================================" << std::endl;
	std::cout << "Nazwa produktu:   " << this->getName() << std::endl;
	std::cout << "Cena produktu:    " << this->getPrice() << std::endl;
	std::cout << "Data zakupu:      " << this->getTimestamp() << std::endl;
	std::cout << "Liczba sztuk:     " << this->getQuanity() << std::endl;
	std::cout << "Totalny koszt:    " << this->getCost() << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << std::endl;
}