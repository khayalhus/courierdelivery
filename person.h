#include <string>
#include <iostream>

using namespace std;

class Person {
    string name; // name of the Person 
    string surname; // surname of the Person
    public:
        Person(string name, string surname) {
            this->name = name; // sets name
            this->surname = surname; // sets surname
        }
        string getName() {
            return this->name; // getter for name
        }
        string getSurname() {
            return this->surname; // getter for surname
        }
};

class Owner : public Person {
    int ownership; // percentage of shares a person holds over a business
    public:
        Owner():Person("undefined", "undefined"){
            ownership = 0; // ownership will be updated during Business object construction
            // default constructor used for owners array intialization
        }
        Owner(string name, string surname):Person(name,surname){
            ownership = 0; // ownership will be updated during Business object construction
        }
        void set_ownership(int percentage) {
            this->ownership = percentage; // updates ownership with calculated percentage by Business class constructor
        }
        int get_ownership() {
            return ownership; // getter for ownership
        }
};

class Courier : public Person {
    string vehicle; // type of vehicle courier uses (car, motorcycle or bicycle)
    Courier * next; // next courier in the Linked List
    public:
        Courier(string name, string surname, string vehicle):Person(name,surname) {
            this->next = NULL;
            if (vehicle.compare("car") == 0 || vehicle.compare("motorcycle") == 0 || vehicle.compare("bicycle") == 0) {
                this->vehicle = vehicle; // set vehicle type if it is a valid input
            } else {
                cout << "ERROR: Invalid Vehicle Type" << endl;
            }
        }
        bool operator==(Courier& in_object) { // const keywords were removed so parent class public member functions can be called
            if (this->getSurname().compare(in_object.getSurname()) == 0) { // checks surname first because given main.cpp has all names as "Courier"
                if (this->getName().compare(in_object.getName()) == 0) { // checks name as well just in case
                    if (this->vehicle.compare(in_object.vehicle) == 0) { // checks vehicle type to make sure
                        return true; // true if it is the one
                    }
                }
            }
            return false; // return false if they are not equal
        }
        Courier * getNext() {
            return this->next; // getter for next Courier in the Linked List
        }
        void setNext(Courier * target) {
            this->next = target; // setter for the next Courier in the Linked List
        }
        string getVehicleType() {
            return vehicle; // getter for vehicle type
        }
};