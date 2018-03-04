//
// Created by Krystian Duma on 08/04/2017.
//

#include <fstream>
#include <iostream>
#include <istream>
#include <iomanip>
#include "TrainingCollection.h"

TrainingCollection::TrainingCollection () {

}

void TrainingCollection::addTraining ( Training training ) {
	trainings.push_back(training);
}

void TrainingCollection::store ( std::string file_name ) {
	std::ofstream file(file_name);

	for ( auto training : trainings ) {
		file << training.getId() << "\t";
		file << training.getTitle() << "\t";
		file << training.getStartDate() << "\t";
		file << training.getDuration() << "\n";
	}

	file.close();
}

void TrainingCollection::load ( std::string file_name ) {
	trainings.clear();
	std::ifstream file(file_name);

	while ( file ){
		int id;
		std::string title;
		int start_date;
		int duration;

		if(!(file >> id))
			break;
		std::getline(file, title, '\t'); // pozbywamy się tabulatora
		std::getline(file, title, '\t');
		file >> start_date;
		file >> duration;

		addTraining(Training(id, title, start_date, duration));
	}

	file.close();
}

void TrainingCollection::print () {
	int max_title_length = 15;

	for ( auto training : trainings ) {
		int length = training.getTitle().length();
		if(length > max_title_length)
			max_title_length = length;
	}


	print_table_header(max_title_length);
	for ( auto training : trainings ) {
		training.print_table_row(max_title_length);
	}
	print_table_footer(max_title_length);
}

void TrainingCollection::print_table_header ( int title_length ) {
	print_table_footer(title_length);
	std::cout << std::left << std::setw(0) << "| ";
	std::cout << std::left << std::setw(3) << "ID";
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(title_length) << "Nazwa Szkolenia";
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(10) << "Data";
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(2) << "Dł";
	std::cout << std::left << std::setw(0) << " |" << std::endl;

	print_table_footer(title_length);
}

void TrainingCollection::print_table_footer ( int title_length ) {
	std::cout << std::left << std::setw(0) << "+-----+-";
	for ( int i = 0; i < title_length; ++i ) {
		std::cout << "-";
	}
	std::cout << std::left << std::setw(0) << "-+------------+----+" << std::endl;
}

TrainingCollection TrainingCollection::fromPeriod ( int from_date, int to_date ) {
	TrainingCollection CollectionToReturn;

	for ( auto training : trainings ) {
		if(training.getStartDate() >= from_date && training.getStartDate() <= to_date)
			CollectionToReturn.addTraining(training);
	}

	return CollectionToReturn;
}

bool TrainingCollection::hasID ( int id ) {
	for ( auto training : trainings ) {
		if(training.getId() == id)
			return true;
	}

	return false;
}

Training TrainingCollection::getByID ( int id ) {
	for ( auto training : trainings ) {
		if(training.getId() == id)
			return training;
	}

	return Training();
}

int TrainingCollection::getNextID () {
	int max_id = 0;

	for ( auto training : trainings ) {
		if(training.getId() > max_id)
			max_id = training.getId();
	}

	return max_id + 1;
}
