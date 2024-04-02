#include "person.h"
#include "cstring"

using namespace std;

person::person(int id, int age, std::string first_name, std::string last_name) {
    setFirstName(first_name);
    setAge(age);
    setId(id);
    setLastName(last_name);
}

person::person() {
    char a[15] = "              ";
    setFirstName(a);
    setLastName(a);
    setAge(0);
    setId(0);
}

string person::getLastName() const {
    return Last_name;
}

void person::setLastName(const std::string lastName) {
    if (lastName.size() > 15)
        Last_name = lastName.substr(0, 15);
    else
        Last_name = lastName;
}

std::string person::getFirstName() const {
    return First_name;
}

void person::setFirstName(const std::string firstName) {
    if (firstName.size() > 15)
        First_name = firstName.substr(0, 15);
    else
        First_name = firstName;
}

int person::getId() const {
    return Id;
}

void person::setId(int id) {
    Id = id;
}

int person::getAge() const {
    return Age;
}

void person::setAge(int age) {
    Age = age;
}


std::string person::to_string() {
    return "id: " + std::to_string(getId()) + " first Name: " + getFirstName()
           + " last Name: " + getLastName() + " Age: " + std::to_string(getAge())+"\n";
}
