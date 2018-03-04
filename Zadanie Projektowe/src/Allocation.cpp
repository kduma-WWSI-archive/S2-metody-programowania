//
// Created by Krystian Duma on 08/04/2017.
//

#include "Allocation.h"

Allocation::Allocation ( int coach_id, int training_id ) : coach_id(coach_id), training_id(training_id) { }

int Allocation::getCoachId () const {
	return coach_id;
}

void Allocation::setCoach_id ( int coach_id ) {
	Allocation::coach_id = coach_id;
}

int Allocation::getTrainingId () const {
	return training_id;
}

void Allocation::setTraining_id ( int training_id ) {
	Allocation::training_id = training_id;
}
