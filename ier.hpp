#ifndef IER_H
#define IER_H

#include "person.hpp"
#include <memory>
#include <sstream>
#include <vector>

class Student : public Person {
  private:
    int id;
    std::string group;
    std::weak_ptr<Teacher> advisor;

  public:
    Student(const std::string &lN = "", const std::string &fN = "", int a = 0,
            const std::string &g = "", int i = 0, const std::string &gr = "")
        : Person(lN, fN, a, g), id(i), group(gr) {}

    int get_studentId() const { return id; }
    std::string get_studentGrup() const { return group; }

    void set_advisor(std::shared_ptr<Teacher> t);
    std::string get_advisorName() const;

    void print() const override {
        std::cout << "Student: " << firstName << " " << lastName
                  << ", ID: " << id << ", Group: " << group;

        (std::cout << advisor.expired())
            ? "\n"
            : ", Advisor: " + get_advisorName() + "\n";
    }

    std::string to_string() const override {
        std::ostringstream oss;
        oss << "Student: " << firstName << " " << lastName << ", ID: " << id
            << ", Group: " << group;

        (oss << advisor.expired()) ? "\n"
                                   : ", Advisor: " + get_advisorName() + "\n";

        return oss.str();
    }
};

class Teacher : public Person {
  private:
    int tId;
    std::string department;
    std::vector<std::shared_ptr<Student>> advicees;

  public:
    Teacher(const std::string &lN = "", const std::string &fN = "", int a = 0,
            const std::string &g = "", int i = 0, const std::string &dep = "")
        : Person(lN, fN, a, g), tId(i), department(dep) {}

    int get_teacherId() const { return tId; }
    std::string get_teacherDepartment() const { return department; }

    void set_teacherId(int i) { tId = i; }
    void set_teacherDepartment(const std::string &dep) { department = dep; }

    void add_student(std::shared_ptr<Student> student) {
        advicees.push_back(student);
        student->set_advisor(std::shared_ptr<Teacher>(this));
    }

    void add_student_shared(std::shared_ptr<Student> st,
                            std::shared_ptr<Teacher> self) {
        advicees.push_back(st);
        st->set_advisor(self);
    }

    size_t get_students_count() const { return advicees.size(); }

    std::string get_student_list() const {
        if (advicees.empty()) {
            return "None";
        }

        std::string res;
        for (const auto &s : advicees) {
            if (!res.empty())
                res += ", ";
            res += s->get_firstName() + " " + s->get_lastName();
        }

        return res;
    }

    void print() const override {
        std::cout << "Teacher: " << firstName << " " << lastName
                  << ", ID: " << tId << ", Dept: " << department
                  << ", Students: (" << advicees.size()
                  << "): " << get_student_list();
    }

    std::string to_string() const override {
        std::ostringstream oss;
        oss << "Teacher: " << firstName << " " << lastName << ", ID: " << tId
            << ", Dept: " << department << ", Students: (" << advicees.size()
            << "): " << get_student_list();
        return oss.str();
    }
};

inline void Student::set_advisor(std::shared_ptr<Teacher> t) { advisor = t; }

inline std::string Student::get_advisorName() const {
    if (auto t = advisor.lock()) {
        return t->get_firstName() + " " + t->get_lastName();
    }
    return "None";
}
#endif
