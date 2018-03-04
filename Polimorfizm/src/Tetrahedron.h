#ifndef TETRAHEDRON_H
    #define TETRAHEDRON_H
    #include "Shape.h"

    class Tetrahedron : public Shape {
        protected:
            double a;

        public:
            Tetrahedron();
            Tetrahedron(double a);
            virtual double volume();
            virtual double surface_area();
            virtual void ask_user_for_data();
    };

#endif