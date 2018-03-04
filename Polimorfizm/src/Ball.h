#ifndef BALL_H
    #define BALL_H
    #include "Shape.h"

    class Ball : public Shape {
        protected:
            double r;

        public:
            Ball();
            Ball(double r);
            virtual double volume();
            virtual double surface_area();
            virtual void ask_user_for_data();
    };

#endif
