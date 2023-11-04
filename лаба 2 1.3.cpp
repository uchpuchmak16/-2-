/*пользователь сам вводит имена и оценки по инструкции*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {

    std::vector<int> grades; /* вектор для оценок*/
    std::vector<std::string> names; /* вектор для имен*/
    int grade; /* только целые числа для оценок*/
    std::string name; /*string, чтобы работать со строчками*/

    std::cout << "введите оценки учеников ( число меньше 0 для завершения ввода):" << std::endl;
    std::cout << "вводите число от 0 до 100 без каких-либо символов и знаков" << std::endl;

    while (true) {
        std::cin >> grade; /* пользователь вводит оценки больше нуля*/
        if (grade < 0 || grade > 100) {
            std::cout << "некорректная оценка! пожалуйста, введите значение от 0 до 100." << std::endl;
            break;
        }
        grades.push_back(grade);
        std::cin.ignore();
        std::cout << "чья это оценка? " << std::endl;
        std::cout << "ведите имя ученика: ";
        std::getline(std::cin, name);
        names.push_back(name); /*push using for adding in vector*/
    }

    //  мода
    std::map<int, int> gradeCount; /*ассоциативный контейнер для присваивания значениям ключей, чтобы искать моду было проще*/
    for (const auto& grade : grades) {
        gradeCount[grade]++;
    }

    int mode = 0;
    int maxCount = 0;
    for (const auto& pair : gradeCount) {
        if (pair.second > maxCount) {
            mode = pair.first;
            maxCount = pair.second;
        }
    }

    // среднее значение
    double sum = 0;
    for (const auto& grade : grades) {
        sum += grade;
    }
    double average = sum / grades.size();

    //  медиана
    std::sort(grades.begin(), grades.end()); /* программа сортирует значения в порядке возрастания*/
    double median;
    if (grades.size() % 2 == 0) {
        median = (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0;
    }
    else {
        median = grades[grades.size() / 2];
    }

    // вывод имен учеников с оценками, соответствующими моде
    std::cout << "ученики с самой распространненой оценкой " << mode << ":" << std::endl;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] == mode) {
            std::cout << names[i] << std::endl;
        }
    }
    std::cout << "медиана: " << median << std::endl;
    std::cout << "среднее значение: " << average << std::endl;
    return 0;
}