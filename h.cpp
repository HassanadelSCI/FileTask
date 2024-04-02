//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include "person.h"
//
//using namespace std;
//
//int main() {
//   //  Writing to file
//    person p1;
//    ofstream outCredit{"persons_data.dat", ios::out | ios::binary};
//    if (!outCredit) {
//        cerr << "File could not be opened." << endl;
//        exit(EXIT_FAILURE);
//    }
//    for (int i = 1; i < 10; ++i) {
//        char firstname[15] = "hassan ";
//        char lastname[15] = "adel";
//        int age = i*10;
//        int id = i;
//        p1 = person(id, age, firstname, lastname);
//        //  cout << p1.getId() << " " << p1.getAge() << " " << p1.getFirstName() << " " << p1.getLastName() << endl;
//        outCredit.write(reinterpret_cast<const char *>(&p1), sizeof(person));
//    }
//    outCredit.close(); // Close the ofstream
//
//    // Reading from file
//    ifstream inCredit{"persons_data.dat", ios::in | ios::binary | ios::app};
//    if (!inCredit) {
//        cerr << "File could not be opened." << endl;
//        exit(EXIT_FAILURE);
//    }
//    person p2;
//    for (int i = 1; i < 10; ++i) {
//        inCredit.seekg((i-1)* sizeof(person));
//        inCredit.read(reinterpret_cast<char *>(&p2), sizeof(person));
//        cout<<p2.to_string();
//    }
//    inCredit.close(); // Close the ifstream
//
//    cout<<"end";
//    return 0;
//}
//




//    for (int i = 1; i <= 1000; ++i) {
//        person p1 = person();
//
//        writePerson(p1, i - 1);
//    }
//    string a;
//
//    int writeIndex=1;
//    int input;
//    while(true){
//        cout<<"Enter 1 to: Insert Object into the Offset Identified by ID\n"
//              "Enter 2 to: Get Object from the Index Identified by ID \n"
//              "Enter 0 to terminate\n";
//        cin>>input;
//        cin.ignore();
//        if(input==0){ exit(0);
//            }
//        if(input==1) {
//            string firstname;
//            string lastname;
//            int age;
//            int id = writeIndex;
//            cout << "Enter the first Name: \n";
//            getline(cin, firstname);
//            cout << "Enter the Last Name: \n";
//            getline(cin, lastname);
//            cout << "Enter the Age: \n";
//            cin >> age;
//            cin.ignore();
//            person p1 = person(id, age, firstname, lastname);
//            writePerson(p1,writeIndex++);
//        }
//        if(input==2){  int i;
//            cout<<"Enter the id \n";
//            cin>>i;
//            cin.ignore();
//            person p1=getPerson(i);
//            cout<<p1.to_string()<<endl;
//        }
//    }