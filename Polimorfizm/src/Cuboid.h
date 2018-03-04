#ifndef CUBOID_H
    #define CUBOID_H
    #include "Shape.h"

    class Cuboid : public Shape {
        protected:
            double a, b, h;

        public:
            Cuboid();
            Cuboid(double a, double b, double h);
            virtual double volume();
            virtual double surface_area();
            virtual void ask_user_for_data();
    };

#endif
