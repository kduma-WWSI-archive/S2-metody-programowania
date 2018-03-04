#ifndef CONE_H
    #define CONE_H
    #include "Shape.h"

    class Cone : public Shape {
        protected:
            double h, r;

        public:
            Cone();
            Cone(double h, double r);
            double volume() override;
            double surface_area() override;
            double slant_height();
            void ask_user_for_data() override;
    };

#endif
