#include "src/Store.h"
#include "src/UI.h"
#include "src/logic.h"


int main () {
	Store Storage;

	while(true) {
		switch (print_main_menu()){
			case 0:
			default:
				return 0;

			case 1:
				create_new_coach(Storage);
				break;

			case 2:
				create_new_training(Storage);
				break;

			case 3:
				trainings_from_period(Storage);
				break;

			case 4:
				trainings_assigned_to_trainer(Storage);
				break;

			case 5:
				search_for_faulty_assignments(Storage);
				break;
		}
	}
}

