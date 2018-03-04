#include <iostream>
#include <math.h>
#include "Cone.h"

Cone::Cone() {}

Cone::Cone(double h, double r) : h(h), r(r) {}

double Cone::volume() {
    return 1.0/3.0 * M_PI * pow(r, 2) * h;
}

double Cone::surface_area() {
    return M_PI * r * (r + slant_height());
}

double Cone::slant_height() {
    return sqrt(pow(h, 2) + pow(r, 2));
}

void Cone::ask_user_for_data() {
    std::cout << "Podaj promien podstawy: "; std::cin >> r;
    std::cout << "Podaj wysokosc:         "; std::cin >> h;
}
