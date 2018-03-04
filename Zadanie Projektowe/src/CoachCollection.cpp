//
// Created by Krystian Duma on 08/04/2017.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include "CoachCollection.h"


CoachCollection::CoachCollection () {

}

void CoachCollection::addCoach ( Coach coach ) {
	coaches.push_back(coach);
}

void CoachCollection::store ( std::string file_name ) {
	std::ofstream file(file_name);

	for ( auto coach : coaches ) {
		file << coach.getId() << "\t";
		file << coach.getName() << "\n";
	}

	file.close();
}

void CoachCollection::load ( std::string file_name ) {
	coaches.clear();
	std::ifstream file(file_name);

	while ( file ){
		int id;
		std::string name;

		if(!(file >> id))
			break;
		std::getline(file, name, '\t'); // pozbywamy się tabulatora
		std::getline(file, name, '\n');

		addCoach(Coach(id, name));
	}

	file.close();
}


void CoachCollection::print () {
	int max_name_length = 6;

	for ( auto coach : coaches ) {
		int length = coach.getName().length();
		if(length > max_name_length)
			max_name_length = length;
	}

	print_table_header(max_name_length);
	for ( auto coach : coaches ) {
		coach.print_table_row(max_name_length);
	}
	print_table_footer(max_name_length);
}

void CoachCollection::print_table_header ( int name_length ) {
	print_table_footer(name_length);
	std::cout << std::left << std::setw(0) << "| ";
	std::cout << std::left << std::setw(3) << "ID";
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(name_length) << "Trener";
	std::cout << std::left << std::setw(0) << " |" << std::endl;
	print_table_footer(name_length);
}

void CoachCollection::print_table_footer ( int name_length ) {
	std::cout << std::left << std::setw(0) << "+-----+-";
	for ( int i = 0; i < name_length; ++i ) {
		std::cout << "-";
	}
	std::cout << std::left << std::setw(0) << "-+" << std::endl;
}

bool CoachCollection::hasID ( int id ) {
	for ( auto coach : coaches ) {
		if(coach.getId() == id)
			return true;
	}

	return false;
}

Coach CoachCollection::getByID ( int id ) {
	for ( auto coach : coaches ) {
		if(coach.getId() == id)
			return coach;
	}

	return Coach();
}

int CoachCollection::getNextID () {
	int max_id = 0;

	for ( auto coach : coaches ) {
		if(coach.getId() > max_id)
			max_id = coach.getId();
	}

	return max_id + 1;
}
