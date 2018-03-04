//
// Created by Krystian Duma on 08/04/2017.
//

#include <iostream>
#include <iomanip>
#include "Training.h"

int Training::getId () const {
	return id;
}

void Training::setId ( int id ) {
	Training::id = id;
}

const std::string &Training::getTitle () const {
	return title;
}

void Training::setTitle ( const std::string &title ) {
	Training::title = title;
}

int Training::getStartDate () const {
	return start_date;
}

void Training::setStart_date ( int start_date ) {
	Training::start_date = start_date;
}

int Training::getDuration () const {
	return duration;
}

void Training::setDuration ( int duration ) {
	Training::duration = duration;
}

Training::Training () {

}

Training::Training ( int id, const std::string &title, int start_date, int duration ) : id(id), title(title),
                                                                                        start_date(start_date),
                                                                                        duration(duration) { }

void Training::print () {
	std::cout << "ID:               " << id << std::endl;
	std::cout << "Nazwa szkolenia:  " << title << std::endl;
	std::cout << "Data rozpoczęcia: " << start_date << std::endl;
	std::cout << "Czas trwania:     " << duration << std::endl;
}

void Training::print_table_row ( int title_length ) {
	std::cout << std::left << std::setw(0) << "| ";
	std::cout << std::left << std::setw(3) << id;
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(title_length) << title;
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(10) << getFormattedStartDate();
	std::cout << std::left << std::setw(0) << " | ";
	std::cout << std::left << std::setw(2) << duration;
	std::cout << std::left << std::setw(0) << " |" << std::endl;
}

std::string Training::getFormattedStartDate () const {
	int year = start_date/10000;
	int month = (start_date-year*10000)/100;
	int day = start_date-year*10000-month*100;

	return std::to_string(year) + std::string("-") + std::to_string(month) + std::string("-") + std::to_string(day);
}

std::string Training::getFormattedEndDate () const {
	int year = (start_date+duration)/10000;
	int month = ((start_date+duration)-year*10000)/100;
	int day = (start_date+duration)-year*10000-month*100;

	return std::to_string(year) + std::string("-") + std::to_string(month) + std::string("-") + std::to_string(day);
}
