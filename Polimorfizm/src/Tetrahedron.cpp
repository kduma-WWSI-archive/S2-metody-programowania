#include <iostream>
#include <cmath>
#include "Tetrahedron.h"

Tetrahedron::Tetrahedron() {}

Tetrahedron::Tetrahedron(double a) : a(a) {}

double Tetrahedron::volume() {
    return (1.0/12.0) * pow(a,3) * sqrt(2);
}

double Tetrahedron::surface_area() {
    return pow(a,2) * sqrt(3);
}

void Tetrahedron::ask_user_for_data() {
    std::cout << "Podaj krawedz: ";
    std::cin >> a;
}
