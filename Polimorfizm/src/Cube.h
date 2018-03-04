#ifndef CUBE_h
    #define CUBE_h
    #include "Cuboid.h"

    class Cube : public Cuboid {
        public:
            Cube();
            Cube(double a);
            virtual void ask_user_for_data();
    };

#endif