#include <string>
#include "person.h"

using namespace std;

class Business {
    string name;
    string address;
    Owner * owners;
    Courier * couriers;
    int numberOfOwners;
    public:
        Business(string name, string address, Owner * owners, int numberOfOwners) {
            //The amount of “ownership” should be adjusted during construction as well.
            this->name = name;
            this->address = address;
            this->owners = new Owner[numberOfOwners];
            for (int i = 0; i < numberOfOwners; i++) {
                this->owners[i] = owners[i];
            }
            //this->owners = owners;
            this->numberOfOwners = numberOfOwners;
            for (int i = 0; i < numberOfOwners; i++) {
                this->owners[i].set_ownership(100 / numberOfOwners);
            }
        }
        void hire_courier(Courier newcourier) {
            //Insert courier to list/array
            Courier * alt = new Courier(newcourier.getName(), newcourier.getSurname(), newcourier.getVehicleType());
            if (couriers == NULL) {
                couriers = alt;
            } else {
                Courier * traverse = couriers;
                while(traverse->getNext() != NULL) {
                    traverse = traverse->getNext();
                }
                traverse->setNext(alt);
            }
        }
        void fire_courier(Courier target) {
            //Searches the courier and removes it from the list/array
            //If the courier does not exist it should print an error message
            //You should overload == operator for Courier class which is required for the search part.
            Courier * traverse = couriers;
            Courier * tail = NULL;
            while(traverse != NULL) {
                if (*traverse == target) {
                    if (tail == NULL) {
                        couriers = traverse->getNext();
                    } else {
                        tail->setNext(traverse->getNext());
                    }
                    delete traverse;
                    return;
                }
                tail = traverse;
                traverse = traverse->getNext();
            }
        }
        void list_couriers() {
            //This method prints all information (name, surname, vehicle_type) about all couriers to screen.
            Courier * traverse = couriers;
            while (traverse != NULL) {
                cout << traverse->getName() << " " << traverse->getSurname() << " " << traverse->getVehicleType() << endl;
                traverse = traverse->getNext();
            }
        }
        void list_owners() {
            //This method prints all information (name, surname, ownership) about all owners to screen.
            for (int i = 0; i < numberOfOwners; i++) {
                cout << this->owners[i].getName() << " " << this->owners[i].getSurname() << " " << this->owners[i].get_ownership() << endl;
            }
        }
        int calculate_shipment_capacity() {
            //This method should sum up total transportation capacity.
            Courier * traverse = couriers;
            int totalShipmentCapacity = 0;
            while (traverse != NULL) {
                string vehicleType = traverse->getVehicleType();
                if (vehicleType.compare("car") == 0) {
                    totalShipmentCapacity += 200;
                } else if (vehicleType.compare("motorcycle") == 0) {
                    totalShipmentCapacity += 35;
                } else if (vehicleType.compare("bicycle") == 0) {
                    totalShipmentCapacity += 10;
                }
                traverse = traverse->getNext();
            }
            return totalShipmentCapacity;
        }
        void operator () () {
            // it should print all information about the business (i.e., name, address, owners, couriers).
            cout << this->name << " " << this->address << endl;
            list_owners();
            list_couriers();
        }
        Courier& operator [] (int index) {
            //it should return courier with the given index.
            //If the index is invalid, it should print an error message.
            Courier * traverse = couriers;
            for (int i = 0; i < index; i++) {
                if (traverse->getNext() == NULL) {
                    cout << "ERROR: Invalid courier index" << endl;
                    return *traverse; // NEEDS A FIX
                }
                traverse = traverse->getNext();
            }
            return *traverse;
        }
};