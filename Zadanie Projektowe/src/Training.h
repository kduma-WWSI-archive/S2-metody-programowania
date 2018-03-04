//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_TRAINING_H
#define ZADANIE_PROJEKTOWE_TRAINING_H


#include <string>

class Training {
private:
	int id;
	std::string title;
	int start_date;
	int duration;

public:
	Training ( int id, const std::string &title, int start_date, int duration );
	Training ();
	int getId () const;
	void setId ( int id );
	const std::string &getTitle () const;
	void setTitle ( const std::string &title );
	int getStartDate () const;
	std::string getFormattedStartDate () const;
	std::string getFormattedEndDate () const;
	void setStart_date ( int start_date );
	int getDuration () const;
	void setDuration ( int duration );
	void print ();
	void print_table_row ( int title_length );
};


#endif //ZADANIE_PROJEKTOWE_TRAINING_H
