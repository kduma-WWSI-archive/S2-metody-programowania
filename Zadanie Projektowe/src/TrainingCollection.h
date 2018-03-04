//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_TRAININGCOLLECTION_H
#define ZADANIE_PROJEKTOWE_TRAININGCOLLECTION_H

#include <vector>
#include "Training.h"

class TrainingCollection {
public:
	std::vector<Training> trainings;
	TrainingCollection ();
	void addTraining(Training training);
	void store ( std::string file_name );
	void load ( std::string file_name );

	void print ();
	void print_table_header(int title_length);
	void print_table_footer(int title_length);
	TrainingCollection fromPeriod ( int from_date, int to_date );
	Training getByID ( int id );
	bool hasID ( int id );
	int getNextID ();
};


#endif //ZADANIE_PROJEKTOWE_TRAININGCOLLECTION_H
