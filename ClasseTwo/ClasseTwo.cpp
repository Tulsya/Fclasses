#include <iostream>
#include <string>
#include <locale>

class Counter {
private:
    int value; 

public:
    Counter(int start_value = 1) : value(start_value) {}

    void Increment() {
        value++;
    }

    void Decrement() {
        value--;
    }

    int GetValue() const {
        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::system("chcp 1251");

    std::string userChoice;
    int startValue = 1;

    std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
    std::cin >> userChoice;

    if (userChoice == "да") {
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> startValue;
    }

    Counter counter(startValue);

    while (true) {
        char command;
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.Increment();
            break;
        case '-':
            counter.Decrement();
            break;
        case '=':
            std::cout << "Текущее значение счетчика: " << counter.GetValue() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            return 0;
        default:
            std::cout << "Неверная команда. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}
