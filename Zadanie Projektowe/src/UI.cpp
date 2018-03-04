//
// Created by Krystian Duma on 10/04/2017.
//

#include <iostream>
#include "UI.h"

int print_main_menu () {
	int option = 0;

	while (true) {
		std::cout << "--- MENU GŁÓWNE ---" << std::endl;
		std::cout << "1) Dodaj nowego trenera" << std::endl;
		std::cout << "2) Dodaj nowe szkolenie" << std::endl;
		std::cout << "3) Lista szkoleń z zadanego okresu" << std::endl;
		std::cout << "4) Lista wszystkich szkoleń przydzielonych do wskazanego trenera" << std::endl;
		std::cout << "5) Lista błędnych przydziałów" << std::endl;
		std::cout << std::endl;
		std::cout << "0) Zakończ program i zapisz zmiany" << std::endl;
		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> option;

		if(option >= 0 && option <= 5)
			break;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "!!! BŁĄD !!!" << std::endl;
		std::cout << "Wybrałeś nieprawidłową opcję. Spróbuj ponownie jeszcze raz." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	return option;
}

int print_get_date_prompt () {
	int date = 0, year, month, day;
	std::cout << "  Rok:     > "; std::cin >> year;
	std::cout << "  Miesiąc: > "; std::cin >> month;
	std::cout << "  Dzień:   > "; std::cin >> day;

	date += day;
	date += month * 100;
	date += year * 10000;

	return date;
}

int print_get_search_trainer_id () {
	int trainer_id = 0;
	std::cout << "Podaj identyfikator trenera do wyszukania." << std::endl;
	std::cout << "Jeśli chcesz anulować wyszukiwanie podaj 0." << std::endl;
	std::cout << "> ";

	std::cin >> trainer_id;
	return trainer_id;
}
