#ifndef SHAPE_H
    #define SHAPE_H

    class Shape {
        public:
            virtual double volume() = 0;
            virtual double surface_area() = 0;
            virtual void ask_user_for_data() = 0;
    };

#endif
