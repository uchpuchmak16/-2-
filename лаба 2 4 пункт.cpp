/*программа для многомодальной моды с вводом оценок пользователем*/
#include <vector>
#include <algorithm> /*делаю через итераторы, поэтому добавляю эту бибилиотеку*/
#include <map>
#include <iostream>


 int main() {
     setlocale(LC_ALL, "Rus");
    std::vector<std::string> names = { "Иволгин Роман", "Петров Николай", "Лебедева Мария", "Вологодская Елена", "Семенов Андрей", "Тимощук Валентин", "Окладов Сергей", "Яковлев Лев", "Балконская Юлия", "Ахматова Анастасия" };
    std::vector<int> marks;

    for (int i = 0; i < names.size(); i++) {
        int mark;
        std::cout << "введите оценку студента от 0 до 100 " << names[i] << ": ";
        std::cin >> mark;
        marks.push_back(mark); /*добавление элемента в вектор с оценками */
    }

    // мода
    std::map<int, int> countMap;
    for (int i = 0; i < marks.size(); i++) {
        countMap[marks[i]]++;
    }
    int maxcount = 0;
    int mostfrequentmark = -1;
    for (auto it = countMap.begin(); it != countMap.end(); it++) {
        if (it->second > maxcount) {
            maxcount = it->second;
            mostfrequentmark = it->first;
        }
    }

    // средний балл
    double sum = 0;
    for (int i = 0; i < marks.size(); i++) {
        sum += marks[i];
    }
    double averagemark = sum / marks.size();

    // сортируем оценки
    std::sort(marks.begin(), marks.end()); /* сортируем от меньшего к большему*/

    //  медиана
    double median;
    if (marks.size() % 2 == 0) {
        median = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
    }
    else {
        median = marks[marks.size() / 2];
    }

    // Создаем словарь для подсчета количества повторений каждого значения
    std::map<int, int> valueCounts;

    // Проходим по всем значениям и увеличиваем счетчик для каждого значения
    for (const auto& mark : marks) {
        valueCounts[mark]++;
    }

    // Находим максимальное количество повторений
    int maxCount = 0;
    for (const auto& pair : valueCounts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }

    if (!valueCounts.empty()) {
        // вывод значения моды
        std::cout << "значения моды: ";
        for (const auto& pair : valueCounts) {
            if (pair.second == maxCount) {
                std::cout << pair.first << " ";
            }
        }
        std::cout << std::endl;

        // Выводим студентов с оценкой моды
        /*std::cout << "студенты с оценкой " << valueCounts.begin()-> valueCounts.end() << ":" << std::endl;
        for (int i = 0; i < marks.size(); i++) {
            if (marks[i] == valueCounts.begin()->first)  /*тут немного не могу сообразить как выводить все значeния, мода выводится, а имена нет
                std::cout << names[i] << std::endl;*/
    }

    else {
        std::cout << "Мода не найдена" << std::endl;
    }

    std::cout << "средний балл: " << averagemark << std::endl;
    std::cout << "медиана: " << median << std::endl;

}
/* std::cout << "студенты с оценкой " << mostfrequentmark << ":" << std::endl;
    for (int i = 0; i < marks.size(); i++) {
        if (marks[i] == mostfrequentmark) {
            std::cout << names[i] << std::endl;
        } (тут только для одномодальной) */
