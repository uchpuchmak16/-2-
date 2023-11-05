/*у меня почему-то русская локализация работает через раз: пробовала два метода, которые в комментариях, но все равно не получилось, поэтому на английском*/

#include <iostream>
#include <vector>
#include <string>
/*/#include <locale.h>
#include <windows.h> (для этого еще две функции добавляла, но я их удалила)*/ 

    /*setlocale(LC_ALL, "Russian");*/
    std::vector<std::string> names;
    std::vector<int> grades;

    void printStudents() {

        std::cout << "list of students:\n";
        for (size_t i = 0; i < names.size(); i++) {
            std::cout << names[i] << " -- " << grades[i] << "\n";
        }
    }

    void addStudent() {
        std::string name;
        int grade;

        std::cout << "enter name: ";
        std::cin >> name;

        std::cout << "enter mark: ";
        std::cin >> grade;

        names.push_back(name);
        grades.push_back(grade);

        std::cout << "student added successfully\n";
    }

    void removeStudent() {
        std::string name;
        bool found = false;

        std::cout << "enter name which you need to delete: ";
        std::cin >> name;

        for (size_t i = 0; i < names.size(); i++) {
            if (names[i] == name) {
                names.erase(names.begin() + i);
                grades.erase(grades.begin() + i);
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "student deleted successfully\n";
        }
        else {
            std::cout << "this student's name:" << name << " was not found\n";
        }
    }

    int main() {
        int choice;

        do {
            std::cout << "==========  list edit menu ==========\n";
            std::cout << "1. add student in list\n";
            std::cout << "2. delete from list\n";
            std::cout << "3.final list\n";
            std::cout << "0. exit\n";

            std::cout << "enter the number of operation: ";
            std::cin >> choice;
            std::cout << "\n";

            switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                printStudents();
                break;
            case 0:
                std::cout << "exit.\n";
                break;
            default:
                std::cout << "error.try entering again\n";
                break;
            }

            std::cout << "\n";
        } while (choice != 0);

        return 0;
    }
