//
// Created by Krystian Duma on 13/04/2017.
//

#include "logic.h"
#include "UI.h"
#include <iostream>
#include <map>


void search_for_faulty_assignments ( Store &Storage ) {
	std::map<int, std::map<int, std::vector<int>>> Assignments;
	std::map<int, std::map<int, std::vector<int>>>::iterator CoachAssignments;
	std::map<int, std::vector<int>>::iterator DayAssignments;


	for(auto Coach : Storage.Coaches.coaches){
		CoachAssignments = Assignments.find(Coach.getId());
		if (CoachAssignments == Assignments.end()){
			Assignments.insert(std::pair<int, std::map<int, std::vector<int>>>(Coach.getId(), {}));
			CoachAssignments = Assignments.find(Coach.getId());
		}

		TrainingCollection Trainings = Coach.getTrainings(Storage.Allocations, Storage.Trainings);

		for(auto Training : Trainings.trainings){
			for ( int day = 0; day < Training.getDuration(); ++day ) {
				int date = Training.getStartDate() + day;

				DayAssignments = CoachAssignments->second.find(date);
				if (DayAssignments == CoachAssignments->second.end()){
					CoachAssignments->second.insert(std::pair<int, std::vector<int>>(date, {}));
					DayAssignments = CoachAssignments->second.find(date);
				}

				DayAssignments->second.push_back(Training.getId());
			}
		}
	}

	std::map<int, std::vector<int>> FaultyAssignments;
	for(auto Dates : Assignments){
		for(auto Courses : Dates.second){
			if(Courses.second.size() > 1){
				std::map<int, std::vector<int>>::iterator FaultyAssignment;
				FaultyAssignment = FaultyAssignments.find(Dates.first);
				if (FaultyAssignment == FaultyAssignments.end()){
					FaultyAssignments.insert(std::pair<int, std::vector<int>>(Dates.first, {}));
					FaultyAssignment = FaultyAssignments.find(Dates.first);
				}

				for(auto CourseID : Courses.second){
					if(std::find(FaultyAssignment->second.begin(), FaultyAssignment->second.end(), CourseID) == FaultyAssignment->second.end()) {
						FaultyAssignment->second.push_back(CourseID);
					}
				}
			}
		}
	}

	for(auto Assignment : FaultyAssignments){
		Coach Coach = Storage.Coaches.getByID(Assignment.first);
		std::cout << "Trener " << Coach.getName() << " ma przydzielone następujące szkolenia które nachodzą na siebie:" << std::endl;
		for(auto CourseID : Assignment.second){
			Training Training = Storage.Trainings.getByID(CourseID);
			std::cout << " - " << Training.getTitle() << " (" << Training.getId() << ") [" << Training.getFormattedStartDate() << " - " << Training.getFormattedEndDate() << "]" << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

void trainings_assigned_to_trainer ( Store &Storage ) {
	Storage.reload();
	Storage.Coaches.print();

	int trainer_id = 0;
	do {
		trainer_id = print_get_search_trainer_id();
		if(trainer_id == 0)
			return;

	}while(!Storage.Coaches.hasID(trainer_id));

	Coach Coach = Storage.Coaches.getByID(trainer_id);
	TrainingCollection trainings = Coach.getTrainings(Storage.Allocations, Storage.Trainings);
	trainings.print();
}

void trainings_from_period ( Store &Storage ) {
	int from_date, to_date;
	std::cout << "--- Lista szkoleń z zadanego okresu ---" << std::endl;
	std::cout << "Podaj początek szukanego okresu:" << std::endl;
	from_date = print_get_date_prompt();
	std::cout << "Podaj koniec szukanego okresu:" << std::endl;
	to_date = print_get_date_prompt();

	std::cout << std::endl << std::endl << "Znaleziono następujące szkolenia:" << std::endl;
	Storage.Trainings.fromPeriod(from_date, to_date).print();
	std::cout << std::endl << std::endl;
}

void create_new_training ( Store &Storage ) {
	std::string title;
	int start_date;
	int duration;

	std::cout << "Podaj dane tworzonego Szkolenia:" << std::endl;
	std::cout << "  Nazwa szkolenia: ";
	std::cin.ignore(256, '\n');
	std::getline(std::cin, title);

	std::cout << "  Data Rozpoczęcia: " << std::endl;
	start_date = print_get_date_prompt();

	std::cout << "  Czas trwania (Dni): ";
	std::cin >> duration;

	Storage.reload();
	Storage.Coaches.print();

	int coach_id = 0;
	do {
		std::cout << "  ID Trenera: ";
		std::cin >> coach_id;
	}while(!Storage.Coaches.hasID(coach_id));

	Storage.reload();
	int id = Storage.Trainings.getNextID();
	Storage.Trainings.addTraining(
			Training(id, title, start_date, duration)
	);
	Storage.Allocations.addAllocation(
			Allocation(coach_id, id)
	);
	Storage.save();

	std::cout << "Zostało utworzone nowe szkolenie o identyfikatorze: " << id << std::endl;
}

void create_new_coach ( Store &Storage ) {
	std::string name;

	std::cout << "Podaj dane tworzonego trenera:" << std::endl;
	std::cout << "  Imię i nazwisko: ";

	std::cin.ignore(256, '\n');
	std::getline(std::cin, name);

	Storage.reload();
	int id = Storage.Coaches.getNextID();
	Storage.Coaches.addCoach(
			Coach(id, name)
	);
	Storage.save();

	std::cout << "Został utworzony nowy trener o identyfikatorze: " << id << std::endl;
}