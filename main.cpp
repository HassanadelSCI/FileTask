#include <iostream>
#include <fstream>
#include "person.h"

using namespace std;
int id = 1;

void writePerson() {
    int age;
    std::string last_name, first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::fstream file("persons_data.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for updating." << std::endl;
        exit(0);
    }
    file.seekp(id * sizeof(person));
    person p(id, age, first_name, last_name);
    p.add(file);
    file.close();
    id++;
}

void getPerson() {
    int id;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::ifstream file("persons_data.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        exit(0);
    }
    file.seekg(id * sizeof(person));
    person p;
    p.get(file);
    file.close();

    if (p.getId() == id) {
        std::cout << "Last Name: " << p.getLastName() << std::endl;
        std::cout << "First Name: " << p.getFirstName() << std::endl;
        std::cout << "Age: " << p.getAge() << std::endl;
        std::cout << "ID: " << p.getId() << std::endl;
    } else { cout << "Empty person\n"; }
}

int main() {
    const int NUM_PERSONS = 1000;

    // Inserting 1000 blank objects into the file
    std::ofstream file("persons_data.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return 1;
    }
    for (int i = 0; i < NUM_PERSONS; ++i) {
        person p;
        p.add(file);
    }
    file.close();

    int writeIndex = 1;
    int input;
    while (true) {
        cout << "Enter 1 to: Insert Object into the Offset Identified by ID\n"
                "Enter 2 to: Get Object from the Index Identified by ID \n"
                "Enter 0 to terminate\n";
        cin >> input;
        cin.ignore();

        if (input == 0) {
            exit(0);
        }
        if (input == 1) {
            writePerson();
        }
        if (input == 2) {
            getPerson();
        }
    }

}

