#include <iostream>
#include <string>
#include "src/Shape.h"
#include "src/Cone.h"
#include "src/Cylinder.h"
#include "src/Ball.h"
#include "src/Tetrahedron.h"
#include "src/Cuboid.h"
#include "src/Cube.h"

#define TEST

#ifdef TEST
    #include "src/Test.h"

    void test() {
        Test test;

        //region Cuboid - Prostopadłościan
        Cuboid shape_cuboid = Cuboid(10, 20, 30);
        test.assert("Cuboid::volume", shape_cuboid.volume(), 6000);
        test.assert("Cuboid::surface_area", shape_cuboid.surface_area(), 2200);
        //endregion

        //region Cube - Sześcian
        Cube shape_cube = Cube(10);
        test.assert("Cube::volume", shape_cube.volume(), 1000);
        test.assert("Cube::surface_area", shape_cube.surface_area(), 600);
        //endregion

        //region Tetrahedron - Czworościan
        Tetrahedron shape_tetrahedron = Tetrahedron(10);
        test.assert_aprox("Tetrahedron::volume", shape_tetrahedron.volume(), 117);
        test.assert_aprox("Tetrahedron::surface_area", shape_tetrahedron.surface_area(), 173);
        //endregion

        //region Cone - Stożek
        Cone shape_cone = Cone(20, 10);
        test.assert_aprox("Cone::volume", shape_cone.volume(), 2094);
        test.assert_aprox("Cone::surface_area", shape_cone.surface_area(), 1016);
        test.assert_aprox("Cone::slant_height", shape_cone.slant_height(), 22);
        //endregion

        //region Ball - Kula
        Ball shape_ball = Ball(10);
        test.assert_aprox("Ball::volume", shape_ball.volume(), 4188);
        test.assert_aprox("Ball::surface_area", shape_ball.surface_area(), 1256);
        //endregion

        //region Cylinder - Walec
        Cylinder shape_cylinder = Cylinder(10, 20);
        test.assert_aprox("Cylinder::volume", shape_cylinder.volume(), 6283);
        test.assert_aprox("Cylinder::surface_area", shape_cylinder.surface_area(), 1884);
        //endregion
    }

    int main() {
        test();
        return 0;
    }
#else
    void print_results(Shape&b) {
        std::cout << "Objetosc: " << b.volume() << " cm^3\n";
        std::cout << "Pole:     " << b.surface_area() << " cm^2\n";
    }

    void obsluga_bryly(Shape&b) {
        b.ask_user_for_data();
        print_results(b);
    }

    int main() {
        Shape *wsk = new Cube;
        wsk->ask_user_for_data();
        print_results(*wsk);
        delete(wsk);

        Cone b;
        obsluga_bryly(b);

        return 0;
    }
#endif