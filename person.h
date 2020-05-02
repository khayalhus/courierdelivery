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
        string getName() {
            return this->name;
        }
        string getSurname() {
            return this->surname;
        }
};

class Owner : public Person {
    int ownership; // as percentage
    public:
        Owner():Person("undefined", "undefined"){
            //ownership = 0;
        }
        Owner(string name, string surname):Person(name,surname){
            //ownership = 0;
        }
        void set_ownership(int percentage) {
            this->ownership = percentage;
        }
        int get_ownership() {
            return ownership;
        }
};

class Courier : public Person {
    string vehicle; // car (200), motorcycle (35), bicycle (10)
    Courier * next;
    public:
        Courier(string name, string surname, string vehicle):Person(name,surname) {
            this->next = NULL;
            if (vehicle.compare("car") == 0 || vehicle.compare("motorcycle") == 0 || vehicle.compare("bicycle") == 0) {
                this->vehicle = vehicle;
            } else {
                cout << "ERROR: Invalid Vehicle Type" << endl;
            }
        }
        bool operator==(Courier& in_object) {
            if (this->getSurname().compare(in_object.getSurname()) == 0) {
                if (this->getName().compare(in_object.getName()) == 0) {
                    if (this->vehicle.compare(in_object.vehicle) == 0) {
                        return true;
                    }
                }
            }
            return false;
        }
        Courier * getNext() {
            return this->next;
        }
        void setNext(Courier * target) {
            this->next = target;
        }
        string getVehicleType() {
            return vehicle;
        }
};