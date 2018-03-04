//
// Created by Krystian Duma on 08/04/2017.
//

#ifndef ZADANIE_PROJEKTOWE_ALLOCATION_H
#define ZADANIE_PROJEKTOWE_ALLOCATION_H


class Allocation {
private:
	int coach_id;
	int training_id;
public:
	Allocation ( int coach_id, int training_id );
	int getCoachId () const;
	void setCoach_id ( int coach_id );
	int getTrainingId () const;
	void setTraining_id ( int training_id );
};


#endif //ZADANIE_PROJEKTOWE_ALLOCATION_H
