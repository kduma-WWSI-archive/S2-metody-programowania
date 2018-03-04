//
// Created by Krystian Duma on 10/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_STORE_H
#define ZADANIE_PROJEKTOWE_STORE_H


#include "AllocationCollection.h"
#include "CoachCollection.h"
#include "TrainingCollection.h"

class Store {
public:
	AllocationCollection Allocations;
	CoachCollection Coaches;
	TrainingCollection Trainings;
	~Store ();
	Store ();
	void save ();
	void reload ();
};


#endif //ZADANIE_PROJEKTOWE_STORE_H
