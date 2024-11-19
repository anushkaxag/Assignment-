#include <iostream>
#include <vector>
class Passenger {
public:
    std::string name;
    int ticketNumber;


    Passenger(const std::string& n, int t) : name(n), ticketNumber(t) {}


    void displayInfo() const {
        std::cout << "Name: " << name << ", Ticket Number: " << ticketNumber << std::endl;
    }
};

class TicketReservationSystem {
private:
    std::vector<Passenger> passengers;

public:
    void addPassenger(const std::string& name, int ticketNumber) {
        passengers.push_back(Passenger(name, ticketNumber));
    }

    void displayAllPassengers() const {
        for (std::vector<Passenger>::const_iterator it = passengers.begin(); it != passengers.end(); ++it) {
            it->displayInfo(); 
        }
    }

    void searchByTicketNumber(int ticketNumber) const {
        bool found = false;
        for (std::vector<Passenger>::const_iterator it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->ticketNumber == ticketNumber) { 
                std::cout << "Passenger found: ";
                it->displayInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "No passenger found with ticket number: " << ticketNumber << std::endl;
        }
    }
};

int main() {
    TicketReservationSystem system;

    system.addPassenger("Anushka", 101);
    system.addPassenger("Archita", 102);
    system.addPassenger("Ayush", 103);

    std::cout << "All Passengers:" << std::endl;
    system.displayAllPassengers();

    int searchTicketNumber;
    std::cout << "\nEnter ticket number to search: ";
    std::cin >> searchTicketNumber;
    system.searchByTicketNumber(searchTicketNumber);

    return 0;
    
    
    
    
}
