#include <map>
#include "OrdersCollection.h"

OrdersCollection::OrdersCollection () {}

void OrdersCollection::addOrder ( Order order ) {
	Orders.push_back(order);
}

void OrdersCollection::print () {
	for(auto Order : Orders){
		Order.print();
	}
}

double OrdersCollection::getProductOrdersSum ( std::string name ) {
	double sum = 0;
	for(auto Order : Orders){
		if(Order.getName() == name)
			sum += Order.getCost();
	}

	return sum;
}

double OrdersCollection::getProductOrdersInMonth ( int month ) {
	double sum = 0;
	for(auto Order : Orders){
		if(Order.getTimestamp() == month)
			sum += Order.getCost();
	}

	return sum;
}

std::string OrdersCollection::mostPopularProduct () {
	std::map<std::string, int> Products;
	std::map<std::string, int>::iterator product;

	for(auto Order : Orders){
		product = Products.find(Order.getName());
		if(product != Products.end()){
			product->second += Order.getQuanity();
		}else{
			Products.insert(std::pair<std::string, int>(Order.getName(), Order.getQuanity()));
		}
	}

	std::pair<std::string, int> mostPopularProduct;
	for(auto Product : Products){
		if(mostPopularProduct.second < Product.second)
			mostPopularProduct = Product;
	}

	return mostPopularProduct.first;
}
