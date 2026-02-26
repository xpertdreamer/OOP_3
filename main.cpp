#include "ier.hpp"
#include "person.hpp"
#include <cstddef>
#include <memory>
#include <ostream>
#include <vector>

int main() {
    auto teacher1 =
        std::make_shared<Teacher>("Ivanov", "Ivan", 45, "M", 1, "VT");
    auto teacher2 =
        std::make_shared<Teacher>("Vasilieva", "Anna", 56, "F", 2, "Math");

    auto student1 =
        std::make_shared<Student>("Sidorov", "Alexej", 20, "M", 3, "23VD1");
    auto student2 =
        std::make_shared<Student>("Smirnova", "Maria", 19, "F", 4, "23VA2");
    auto student3 =
        std::make_shared<Student>("Kuznetsov", "Pavel", 21, "M", 5, "22FG4");

    teacher1->add_student_shared(student1, teacher1);
    teacher1->add_student_shared(student2, teacher1);
    teacher2->add_student_shared(student3, teacher2);

    std::vector<std::shared_ptr<Person>> persons = {
        teacher1, teacher2, student1, student2, student3};

    std::cout << "ALL PEOPLES:" << std::endl;
    for (size_t i = 0; i < persons.size(); i++) {
        std::cout << i + 1 << ". " << persons[i]->to_string() << std::endl;
    }

    std::cout << "\nPRINT FUNC:" << std::endl;
    for (const auto &p : persons) {
        p->print();
        std::cout << std::endl;
    }

    std::cout << "\nRELATIONSHIPS:" << std::endl;
    std::cout << "Teacher: " << teacher1->get_firstName() << " "
              << teacher1->get_lastName()
              << " rule: " << teacher1->get_student_list() << std::endl;
    std::cout << "Teacher: " << teacher2->get_firstName() << " "
              << teacher2->get_lastName()
              << " rule: " << teacher2->get_student_list() << std::endl;
    std::cout << "Student: " << student1->get_firstName() << " "
              << student1->get_lastName()
              << " ruled by: " << student1->get_advisorName() << std::endl;
    std::cout << "Student: " << student2->get_firstName() << " "
              << student2->get_lastName()
              << " ruled by: " << student2->get_advisorName() << std::endl;
    std::cout << "Student: " << student3->get_firstName() << " "
              << student3->get_lastName()
              << " ruled by: " << student3->get_advisorName() << std::endl;

    return 0;
}
