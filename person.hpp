#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>
#include <string>

class Student;
class Teacher;

class Person {
  protected:
    std::string lastName;
    std::string firstName;
    int age;
    std::string gender;

  public:
    Person(const std::string &lN = "", const std::string &fN = "", int a = 0,
           const std::string &g = "")
        : lastName(lN), firstName(fN), age(a), gender(g) {}

    virtual ~Person() {}

    std::string get_lastName() const { return lastName; }
    std::string get_firstName() const { return firstName; }
    int get_age() const { return age; }
    std::string get_gender() const { return gender; }

    void set_lastName(const std::string &lN) { lastName = lN; }
    void set_firstName(const std::string &fN) { firstName = fN; }
    void set_age(const int a) { age = a; }
    void set_gender(const std::string &g) { gender = g; }

    virtual void print() const {
        std::cout << "Person: " << firstName << " " << lastName
                  << ", Age: " << age << ", Gender: " << gender << std::endl;
    }

    virtual std::string to_string() const {
        std::ostringstream oss;
        oss << "Person: " << firstName << " " << lastName << ", Age: " << age
            << ", Gender: " << gender;
        return oss.str();
    }
};

#endif
