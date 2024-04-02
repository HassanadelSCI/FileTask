#include <iostream>
#include <fstream>
#include <cstring>
#include "person.h"

using namespace std;

void writePerson(person p, int id);


void writePerson(person p, int id) {
    ofstream outCredit{"persons_data.dat", ios::out | ios::binary};

    if (!outCredit) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
    outCredit.seekp(id * sizeof(person));

    outCredit.write(reinterpret_cast<const char *>(&p), sizeof(person));

    outCredit.close();
}

person getPerson(int id) {
    ifstream inCredit("persons_data.dat", ios::in | ios::binary);
    if (!inCredit.is_open()) {
        cerr << "File could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    person p2;
    inCredit.seekg(id * sizeof(person));
    inCredit.read(reinterpret_cast<char *>(&p2), sizeof(person));

    inCredit.close(); // Close the ifstream
    return p2;
}

int main() {
    for (int i = 1; i <= 1000; ++i) {
        person p1 = person();

        writePerson(p1, i - 1);
    }
    string a;

    int writeIndex=1;
    int input;
    while(true){
        cout<<"Enter 1 to: Insert Object into the Offset Identified by ID\n"
              "Enter 2 to: Get Object from the Index Identified by ID \n"
              "Enter 0 to terminate\n";
        cin >> input;
        cin.ignore();

        if(input == 0) {
            exit(0);
        }
        if(input == 1) {
            string firstname;
            string lastname;
            int age;
            int id = writeIndex;
            cout << "Enter the first Name: \n";
            getline(cin, firstname);
            cout << "Enter the Last Name: \n";
            getline(cin, lastname);
            cout << "Enter the Age: ";
            cin >> age;
            cin.ignore();
            person p1 = person(id, age, firstname, lastname);
            writePerson(p1, writeIndex++);
        }
        if(input == 2) {
            int i;
            cin >> i;
            person p1 = getPerson(i);
            cout << p1.to_string();
        }
    }
}

//for (int i = 1; i <= 5; ++i) {
//        person p1 = person(i, i * 10, "hassan", "adel");
//        writePerson(persons_data, p1);
//    }
//
//    for (int i = 1; i <= 5; ++i) {
//        person p = getPerson(persons_data, i);
//        cout << p.to_string() << endl;
//    }
