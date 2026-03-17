#include <iostream>
#include <fstream>
#include <string>
#include "LiSt.h" 

void showMenu() {
    std::cout << "\n--- МЕНЮ УПРАВЛЕНИЯ ОДНОСВЯЗНЫМ СПИСКОМ ---\n";
    std::cout << "1. Создать список (ввод с консоли)\n";
    std::cout << "2. Прочитать данные из файла\n";
    std::cout << "3. Добавить в начало (push_front)\n";
    std::cout << "4. Добавить в конец (push_back)\n";
    std::cout << "5. Добавить по индексу (push_index)\n";
    std::cout << "6. Удалить первый элемент (pop_front)\n";
    std::cout << "7. Удалить последний элемент (pop_back)\n";
    std::cout << "8. Удалить по индексу (pop_index)\n";
    std::cout << "9. Очистить весь список (clear)\n";
    std::cout << "10. Сортировать по значению (Sort)\n";
    std::cout << "11. Показать список (operator<<)\n";
    std::cout << "12. Сохранить в файл\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

int main() {
    list my_list;
    int choice;
    std::string filename = "data.txt";

    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Пожалуйста, введите число.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    std::cin >> my_list;
                    break;

                case 2: {
                    std::ifstream fin("/Users/h/3laba.2/3laba.2/data.txt");
                    if (fin.is_open()) {
                        if(my_list.get_size() != 0)
                            my_list.AddFromFile(fin);
                        else
                            fin >> my_list;
                        std::cout << "Данные из файла загружены.\n";
                        fin.close();
                    } else {
                        std::cout << "Ошибка: Файл " << filename << " не найден.\n";
                    }
                    break;
                }

                case 3: {
                    owner val;
                    std::cout << "Введите значение: ";
                    std::cin >> val;
                    my_list.push_front(val);
                    break;
                }

                case 4: {
                    owner val;
                    std::cout << "Введите значение: ";
                    std::cin >> val;
                    my_list.push_back(val);
                    break;
                }

                case 5: {
                    size_t idx;
                    owner val;
                    std::cout << "Введите индекс: ";
                    std::cin >> idx;
                    std::cout << "Введите значение: ";
                    std::cin >> val;
                    my_list.push_index(idx, val);
                    break;
                }

                case 6:
                    if(my_list.get_size() == 0){
                        std::cout << "Список пуст. ";
                        break;
                    }
                    my_list.pop_front();
                    std::cout << "Первый элемент удален.\n";
                    break;

                case 7:
                    if(my_list.get_size() == 0){
                        std::cout << "Список пуст. ";
                        break;
                    }
                    my_list.pop_back();
                    std::cout << "Последний элемент удален.\n";
                    break;

                case 8: {
                    if(my_list.get_size() == 0){
                        std::cout << "Список пуст. ";
                        break;
                    }
                    size_t idx;
                    std::cout << "Введите индекс для удаления: ";
                    std::cin >> idx;
                    my_list.pop_index(idx);
                    break;
                }

                case 9:
                    if(my_list.get_size() == 0){
                        std::cout << "Список пуст. ";
                        break;
                    }
                    my_list.clear();
                    std::cout << "Список полностью очищен.\n";
                    break;

                case 10:
                    my_list.Sort();
                    std::cout << "Список отсортирован.\n";
                    break;

                case 11:
                    if (my_list.get_size() == 0) {
                        std::cout << "Список пуст.\n";
                    } else {
                        std::cout << "Элементы списка (" << my_list.get_size() << "): " << my_list << "\n";
                    }
                    break;

                case 12: {
                    std::ofstream fout(filename);
                    if (fout.is_open()) {
                        fout << my_list;
                        std::cout << "Данные успешно сохранены в " << filename << "\n";
                        fout.close();
                    } else {
                        std::cout << "Ошибка открытия файла для записи.\n";
                    }
                    break;
                }

                case 0:
                    std::cout << "Программа завершена.\n";
                    return 0;

                default:
                    std::cout << "Неверный пункт меню. Попробуйте снова.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        }
    }
    return 0;
}
