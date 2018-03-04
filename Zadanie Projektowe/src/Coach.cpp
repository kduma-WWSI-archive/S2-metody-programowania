//
// Created by Krystian Duma on 08/04/2017.
//

#include <iomanip>
#include <iostream>
#include "Coach.h"

Coach::Coach ( int id, const std::string &name ) : id(id), name(name) { }

Coach::Coach () { }

int Coach::getId () const {
	return id;
}

void Coach::setId ( int id ) {
	Coach::id = id;
}

const std::string &Coach::getName () const {
	return name;
}

void Coach::setName ( const std::string &name ) {
	Coach::name = name;
}

void Coach::print_table_row ( int name_length ) {
	std::cout << std::left << std::setw(0) << "| ";
	std::cout << std::left << std::setw(3) << id;
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(name_length) << name;
	std::cout << std::left << std::setw(0) << " |" << std::endl;
}


void Coach::print () {
	std::cout << "ID:     " << id << std::endl;
	std::cout << "Trener: " << name << std::endl;
}

TrainingCollection Coach::getTrainings ( AllocationCollection Allocations, TrainingCollection Trainings ) {
	TrainingCollection TrainingsToReturn;

	AllocationCollection trainerAllocations = Allocations.getByCoachID(id);
	for(auto allocation : trainerAllocations.allocations){
		if(Trainings.hasID(allocation.getTrainingId())){
			TrainingsToReturn.addTraining(Trainings.getByID(allocation.getTrainingId()));
		}
	}

	return TrainingsToReturn;
}
