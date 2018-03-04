#include <iostream>
#include <cmath>
#include "Ball.h"

Ball::Ball() {}

Ball::Ball(double r) : r(r) {}

double Ball::volume() {
    return (4.0/3.0)*M_PI*pow(r, 3);
}

double Ball::surface_area() {
    return 4*M_PI*pow(r,2);
}

void Ball::ask_user_for_data() {
    std::cout << "Podaj promien: "; std::cin >> r;
}
