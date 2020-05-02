#include <string>
#include "person.h"

using namespace std;

class Business {
    string name; // name of the business
    string address; // physical address of the business
    Owner * owners; // Dynamic Array holding info about owners
    Courier * couriers; // Linked List holding couriers working for the business
    int numberOfOwners; // amount of owners inside the Dynamic Array
    public:
        Business(string name, string address, Owner * owners, int numberOfOwners) {
            //The amount of “ownership” should be adjusted during construction as well.
            this->name = name; // sets name
            this->address = address; // sets physical address
            /*this->owners = new Owner[numberOfOwners];
            for (int i = 0; i < numberOfOwners; i++) {
                this->owners[i] = owners[i];
            }*/
            this->owners = owners; // sets pointer to parameter
            this->numberOfOwners = numberOfOwners; // sets amount of Owner objects inside owners array
            for (int i = 0; i < numberOfOwners; i++) {
                this->owners[i].set_ownership(100 / numberOfOwners); // calculates and sets percentage of ownership for each owner
            }
        }
        void hire_courier(Courier courier) {
            //Insert courier to list/array
            Courier * newcourier = new Courier(courier.getName(), courier.getSurname(), courier.getVehicleType());
            // allocate memory seperately for the newcourier
            if (this->couriers == NULL) {
                this->couriers = newcourier; // sets the first Courier for the Linked List
            } else {
                Courier * traverse = couriers; // used to traverse the Courier Linked List
                while(traverse->getNext() != NULL) {
                    traverse = traverse->getNext(); // traverses to the last element on the Linked List
                }
                traverse->setNext(newcourier); // adds target as last element's next element
            }
        }
        void fire_courier(Courier target) {
            //Searches the courier and removes it from the list/array
            //If the courier does not exist it should print an error message
            //You should overload == operator for Courier class which is required for the search part.
            Courier * traverse = couriers; // used to traverse the Courier Linked List
            Courier * tail = NULL; // points to Courier before traverse in the Linked List
            while(traverse != NULL) {
                if (*traverse == target) { // calls overloaded operator== in order to test equivalency
                    if (tail == NULL) {
                        couriers = traverse->getNext(); // fire the first courier in the Linked List
                    } else {
                        tail->setNext(traverse->getNext()); // fire the courier in the middle or at the end of the Linked List
                    }
                    delete traverse; // delete the object for the desired Courier
                    return; // return if the courier is found
                }
                tail = traverse;
                traverse = traverse->getNext(); // check next courier
            }
            cout << "ERROR: Desired courier could not be found" << endl; // if courier can't be found, print an error message
        }
        void list_couriers() {
            //This method prints all information (name, surname, vehicle_type) about all couriers to screen.
            Courier * traverse = couriers; // used to traverse the Courier Linked List
            while (traverse != NULL) { // stop if end of Linked List is reached
                cout << traverse->getName() << " " << traverse->getSurname() << " " << traverse->getVehicleType() << endl; // calls parent member functions to print
                traverse = traverse->getNext(); // print the next in the list
            }
        }
        void list_owners() {
            //This method prints all information (name, surname, ownership) about all owners to screen.
            for (int i = 0; i < numberOfOwners; i++) { // stop if info about every Owner has been printed
                cout << this->owners[i].getName() << " " << this->owners[i].getSurname() << " " << this->owners[i].get_ownership() << endl; // calls parent member functions to print
            }
        }
        int calculate_shipment_capacity() {
            //This method should sum up total transportation capacity.
            Courier * traverse = couriers; // used to traverse the Courier Linked List
            int totalShipmentCapacity = 0; // initalize capacity as zero
            while (traverse != NULL) { // stop if end of Linked List is reached
                string vehicleType = traverse->getVehicleType(); // store vehicle type as a variable since it will be used more than once
                if (vehicleType.compare("car") == 0) {
                    totalShipmentCapacity += 200; // if vehicle type is a car, add 200kg to the capacity
                } else if (vehicleType.compare("motorcycle") == 0) {
                    totalShipmentCapacity += 35; // if vehicle type is a motorcycle, add 35kg to the capacity
                } else if (vehicleType.compare("bicycle") == 0) {
                    totalShipmentCapacity += 10; // if vehicle type is a bicycle, add 10kg to the capacity
                }
                traverse = traverse->getNext(); // check for the next courier in the list
            }
            return totalShipmentCapacity; // return the total calculated shipment capacity
        }
        void operator () () {
            // it should print all information about the business (i.e., name, address, owners, couriers).
            cout << this->name << " " << this->address << endl; // print name and address
            list_owners(); // call the function for printing each owner of the business
            list_couriers(); // call the function for printing each courier working for the business
        }
        Courier& operator [] (int index) {
            //it should return courier with the given index.
            //If the index is invalid, it should print an error message.
            Courier * traverse = couriers;
            for (int i = 0; i < index; i++) {
                if (traverse->getNext() == NULL) {
                    cout << "ERROR: Invalid courier index" << endl;
                    exit(1); // the function expects an object to be returned
                    // instead of returning a wrong object, exiting the program was chosen
                }
                traverse = traverse->getNext(); // checks for the next courier in the list
            }
            return *traverse; // return the found courier
        }
};