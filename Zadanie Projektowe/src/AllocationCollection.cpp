//
// Created by Krystian Duma on 08/04/2017.
//

#include <fstream>
#include "AllocationCollection.h"



AllocationCollection::AllocationCollection () {

}

void AllocationCollection::addAllocation ( Allocation allocation ) {
	allocations.push_back(allocation);
}

void AllocationCollection::store ( std::string file_name ) {
	std::ofstream file(file_name);

	for ( auto allocation : allocations ) {
		file << allocation.getCoachId() << "\t";
		file << allocation.getTrainingId() << "\n";
	}

	file.close();
}

void AllocationCollection::load ( std::string file_name ) {
	allocations.clear();
	std::ifstream file(file_name);

	while ( file ){
		int coach_id;
		int training_id;

		if(!(file >> coach_id))
			break;
		file >> training_id;

		addAllocation(Allocation(coach_id, training_id));
	}

	file.close();
}

AllocationCollection AllocationCollection::getByCoachID ( int coach_id ) {
	AllocationCollection AllocationsToReturn;

	for ( auto allocation : allocations ) {
		if(allocation.getCoachId() == coach_id)
			AllocationsToReturn.addAllocation(allocation);
	}

	return AllocationsToReturn;
}
