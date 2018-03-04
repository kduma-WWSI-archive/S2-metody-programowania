//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_COACH_H
#define ZADANIE_PROJEKTOWE_COACH_H


#include <string>
#include "TrainingCollection.h"
#include "AllocationCollection.h"

class Coach {
private:
	int id;
	std::string name;

public:
	Coach ();
	Coach ( int id, const std::string &name );
	int getId () const;
	void setId ( int id );
	const std::string &getName () const;
	void setName ( const std::string &name );
	void print_table_row ( int name_length );
	void print ();
	TrainingCollection getTrainings ( AllocationCollection Allocations, TrainingCollection Trainings );
};


#endif //ZADANIE_PROJEKTOWE_COACH_H
