#include <string>

class person {
private:
    std::string Last_name;
    std::string First_name;
    int Id;
    int Age;
public:
    person();

    person(int id, int age, std::string first_name, std::string last_name);

    void setLastName(std::string lastName);

    std::string getLastName() const;

    void setFirstName(std::string firstName);

    std::string getFirstName() const;

    int getId() const;

    void setId(int id);

    int getAge() const;

    void setAge(int age);

    std::string to_string();
};