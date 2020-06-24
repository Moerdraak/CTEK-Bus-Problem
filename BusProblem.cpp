/* Bus Problem */

#include <iostream>

int main()
{
    const int N = 4; // number of Bus Stops
    unsigned int InputVector[N][2] = { {0,3}, {2,5}, {4,2}, {4,0} }; // User Input 

    unsigned int BusCapacity = 0; // Initialise BusCapacity variable with 0;
    unsigned int PeopleOnBus = 0; // Initialise PeopleOnBus variable with 0;

    for (int I = 0; I < N; I++) { // run through the Number of Bus stops
        // Check for valid input data
        if (InputVector[I][1] < 0 || InputVector[I][1] > 1000) { // Checking the number of people entering Bus
            std::cout << "Input Error, Number of people entering the bus must be between 0 and 1000." << std::endl;
            return 0;
        }
        if (InputVector[I][0] < 0) { // Checking the number of people exiting Bus
            std::cout << "Input Error, Number of people exiting the bus can't be negative." << std::endl;
            return 0;
        }
        if (InputVector[I][0] > PeopleOnBus) { // Checking the number of people exiting Bus
            std::cout << "Input Error, More people are leaving the bus, than are currently on the bus. Seems unlikely." << std::endl;
            return 0;
        }

        PeopleOnBus += InputVector[I][1] - InputVector[I][0]; // At each bus stop subtrack the number of people climbing off and add the number climbing on 
        if (PeopleOnBus > BusCapacity) { // If the number of peoiple currently on the Bus is more thn the BusCapacity variable
            BusCapacity = PeopleOnBus;  // Set the Bus capacity variable to the current number of people on the bus
        }
    }
    if (PeopleOnBus != 0) {
        std::cout << "Input Error, There are still people left on the bus after the last stop. "
            "\nThere's no place in the bus for them to sleep." << std::endl;
    }
    else {
        std::cout << "Minimum Bus Capacity for given Bus route and people load is: " << BusCapacity << std::endl;
    }
    return 0;
}

