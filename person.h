#include <string>
#include <iostream>

using namespace std;

class Person {
    string name;
    string surname;
    public:
        Person(string name, string surname) {
            this->name = name;
            this->surname = surname;
        }
};

class Owner : public Person {
    int ownership; // as percentage
    public:
        Owner();
        Owner(string name, string surname):Person(name,surname){}
        void set_ownership(int percentage) {

        }
};

class Courier : public Person {
    string vehicle; // car (200), motorcycle (35), bicycle (10)
    public:
        Courier(string name, string surname, string vehicle):Person(name,surname) {
            if (vehicle.compare("car") == 0 || vehicle.compare("motorcycle") == 0 || vehicle.compare("bicycle") == 0) {
                this->vehicle = vehicle;
            } else {
                cout << "ERROR: Invalid Vehicle Type" << endl;
            }
        }
        bool operator==(const Courier& other) {
            
        }
};