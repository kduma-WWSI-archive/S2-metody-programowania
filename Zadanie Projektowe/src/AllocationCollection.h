//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_ALLOCATIONCOLLECTION_H
#define ZADANIE_PROJEKTOWE_ALLOCATIONCOLLECTION_H


#include <string>
#include <vector>
#include "Allocation.h"

class AllocationCollection {
public:
	std::vector<Allocation> allocations;
	AllocationCollection ();
	void addAllocation(Allocation allocation);
	void store ( std::string file_name );
	void load ( std::string file_name );
	AllocationCollection getByCoachID ( int coach_id );
};


#endif //ZADANIE_PROJEKTOWE_ALLOCATIONCOLLECTION_H
