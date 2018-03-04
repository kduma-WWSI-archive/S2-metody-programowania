#ifndef TEST_H
    #define TEST_H

    #include <string>
    #include <iostream>
    #include <iomanip>

    class Test {
        int assertions = 0;
    public:
        Test() {
            std::cout << "---------------------------------";
            std::cout << " TEST START ";
            std::cout << "---------------------------------";
            std::cout << std::endl;
        }

    private:
        int failed_assertions = 0;

    public:
        ~Test() {
            std::cout << std::setprecision(4);
            std::cout << "---------------------------------";
            std::cout << " TEST  STOP ";
            std::cout << "---------------------------------";
            std::cout << std::endl;
            std::cout << std::endl;

            int success_rate = ((assertions*1.0-failed_assertions*1.0)/(assertions*1.0))*100;
            std::cout << "Made " << assertions << " assertions, has " << failed_assertions << " failed assertion, success rate is " << success_rate << "%.";

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "--------------------------------";
            std::cout << " REPORT  STOP ";
            std::cout << "--------------------------------";
            std::cout << std::endl;
        }

        void assert_aprox(std::string x, double a, int b){
            assertions++;
            std::cout << std::left << std::setw(0) << "Testing ";
            std::cout << std::left << std::setw(26) << x;
            std::cout << std::left << std::setw(0) << ": ";
            std::cout << std::left << std::setw(0) << "Asserting ";
            std::cout << std::right << std::setw(7) << a;
            std::cout << std::left << std::setw(0) << " is about ";
            std::cout << std::right << std::setw(5) << b;
            std::cout << std::left << std::setw(0) << " - ";
            if((int)a == (int)b){
                std::cout << std::right << std::setw(7) << "ok";
            }else{
                std::cout << std::right << std::setw(7) << "!FAILED";
                failed_assertions++;
            }
            std::cout << std::left << std::setw(0) << std::endl;
        }

        void assert(std::string x, double a, double b){
            assertions++;
            std::cout << std::left << std::setw(0) << "Testing ";
            std::cout << std::left << std::setw(26) << x;
            std::cout << std::left << std::setw(0) << ": ";
            std::cout << std::left << std::setw(0) << "Asserting ";
            std::cout << std::right << std::setw(7) << a;
            std::cout << std::left << std::setw(0) << "  equals  ";
            std::cout << std::right << std::setw(5) << b;
            std::cout << std::left << std::setw(0) << " - ";
            if(a == b){
                std::cout << std::right << std::setw(7) << "ok";
            }else{
                std::cout << std::right << std::setw(7) << "!FAILED";
                failed_assertions++;
            }
            std::cout << std::left << std::setw(0) << std::endl;
        }

    };

#endif
