#include <string>
#include "person.h"

using namespace std;

class Business {
    string name;
    string address;
    Person * owners;
    public:
        Business(string name, string address, Person * owners, int amountOfOwners) {
            //The amount of “ownership” should be adjusted during construction as well.
            this->name = name;
            this->address = address;
            this->owners = owners;
            
        }
        void hire_courier(Courier * newcourier) {
            //Insert courier to list/array
        }
        void fire_courier(Courier * target) {
            //Searches the courier and removes it from the list/array
            //If the courier does not exist it should print an error message
            //You should overload == operator for Courier class which isrequired for the search part.
        }
        void list_couriers() {
            //This method prints all information (name, surname, vehicle_type) about all couriers to screen.
        }
        void list_owners() {
            //This method prints all information (name, surname, ownership) about all owners to screen.
        }
        void calculate_shipment_capacity() {
            //This method should sum up total transportation capacity.
        }
        void operator () () {
            // it should print all information about the business (i.e., name, address, owners, couriers).
            list_couriers();
            list_owners();
        }
        Courier& operator [] (int index) {
            //it should return courier with the given index.
            //If the index is invalid, it should print an error message.
        }
};