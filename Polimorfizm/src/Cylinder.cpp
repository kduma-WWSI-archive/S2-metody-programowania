#include <iostream>
#include <cmath>
#include "Cylinder.h"

Cylinder::Cylinder() {}

Cylinder::Cylinder(double r, double h) : r(r), h(h) {}

double Cylinder::volume() {
    return pow(r, 2) * h * M_PI;
}

double Cylinder::surface_area() {
    return 2*M_PI*pow(r, 2) + 2*r*h*M_PI;
}

void Cylinder::ask_user_for_data() {
    std::cout << "Podaj promien podstawy: "; std::cin >> r;
    std::cout << "Podaj wysokosc:         "; std::cin >> h;
}
