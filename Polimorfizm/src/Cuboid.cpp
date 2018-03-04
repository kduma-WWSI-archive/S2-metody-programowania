#include <iostream>
#include "Cuboid.h"

Cuboid::Cuboid() {}

Cuboid::Cuboid(double a, double b, double h) : a(a), b(b), h(h) {}

double Cuboid::volume() {
    return a*b*h;
}

double Cuboid::surface_area() {
    return 2*a*b + 2*b*h + 2*a*h;
}

void Cuboid::ask_user_for_data() {
    std::cout << "Podaj a: "; std::cin >> a;
    std::cout << "Podaj b: "; std::cin >> b;
    std::cout << "Podaj h: "; std::cin >> h;
}
