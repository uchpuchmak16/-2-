/*имена и оценки задаются в программе*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main() {
    setlocale(LC_ALL, "Rus");
    std::vector<std::string> names = { "Ivolgin Roman", "Petrov Nikolai", "Lebedeva Maria", "Vologodskaya Elena",
                                      "Semenov Andrei", "Timoschuk Artem", "Okladov Sergei", "Yakovlev Lev",
                                      "Balkonskaya Yuliya", "Ahmatova Sofia" }; /*работает поиск только с латиницей. когда вводишь кириллицу программа имен не видит*/
    std::vector<int> scores = { 39, 89, 90, 78, 90, 100, 65, 34, 91, 100 };

    // Вывод оценок по запросу пользователя
    std::string name;
    std::cout << "введите имя студента: ";
    getline(std::cin, name);

    auto it = std::find(names.begin(), names.end(), name);
    if (it != names.end()) {
        int index = std::distance(names.begin(), it);
        std::cout << "оценка: " << scores[index] << std::endl;
    }
    else {
        std::cout << "студента с таким именем нет" << std::endl;
    }

    //  мода
    std::vector<int> counts(101, 0);
    for (int score : scores) {
        counts[score]++;
    }

    int mode = 0;
    int maxCount = 0;
    for (int i = 0; i <= 100; i++) {
        if (counts[i] > maxCount) {
            mode = i;
            maxCount = counts[i];
        }
    }

    std::cout << "мода: " << mode << std::endl;

    //среднее значение
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }

    double average = static_cast<double>(sum) / scores.size();
    std::cout << "среднее значение: " << average << std::endl;

    //  медиана
    std::sort(scores.begin(), scores.end());

    double median;
    if (scores.size() % 2 == 0) {
        median = static_cast<double>(scores[scores.size() / 2 - 1] + scores[scores.size() / 2]) / 2;
    }
    else {
        median = scores[scores.size() / 2];
    }

    std::cout << "медиана: " << median << std::endl;

    return 0;
}
