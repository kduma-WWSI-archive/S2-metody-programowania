#ifndef CYLINDER_H
    #define CYLINDER_H
    #include "Shape.h"

    class Cylinder : public Shape {
        protected:
            double r, h;

        public:
            Cylinder();
            Cylinder(double r, double h);
            virtual double volume();
            virtual double surface_area();
            virtual void ask_user_for_data();
    };

#endif
