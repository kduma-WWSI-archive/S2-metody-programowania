//
// Created by Krystian Duma on 10/04/2017.
//

#include "Store.h"

Store::Store () {
	reload();
}

Store::~Store () {
	save();
}

void Store::reload () {
	Trainings.load("../data/trainings.txt");
	Coaches.load("../data/coaches.txt");
	Allocations.load("../data/allocations.txt");
}

void Store::save () {
	Trainings.store("../data/trainings.txt");
	Coaches.store("../data/coaches.txt");
	Allocations.store("../data/allocations.txt");
}
