#include <iostream>
#include "Cube.h"

Cube::Cube() {}

Cube::Cube(double side) {
    b = h = a = side;
}

void Cube::ask_user_for_data() {
    std::cout << "Podaj a: "; std::cin >> a;
    b = h = a;
}
