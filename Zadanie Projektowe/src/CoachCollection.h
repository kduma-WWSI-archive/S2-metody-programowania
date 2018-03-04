//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_COACHCOLLECTION_H
#define ZADANIE_PROJEKTOWE_COACHCOLLECTION_H


#include <vector>
#include "Coach.h"

class CoachCollection {
public:
	std::vector<Coach> coaches;
	CoachCollection ();
	void addCoach(Coach coach);
	void store ( std::string file_name );
	void load ( std::string file_name );

	void print ();
	void print_table_header(int name_length);
	void print_table_footer(int name_length);
	bool hasID ( int id );
	Coach getByID ( int id );
	int getNextID ();
};


#endif //ZADANIE_PROJEKTOWE_COACHCOLLECTION_H
