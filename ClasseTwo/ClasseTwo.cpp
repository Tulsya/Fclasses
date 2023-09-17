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

    std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
    std::cin >> userChoice;

    if (userChoice == "��") {
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> startValue;
    }

    Counter counter(startValue);

    while (true) {
        char command;
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.Increment();
            break;
        case '-':
            counter.Decrement();
            break;
        case '=':
            std::cout << "������� �������� ��������: " << counter.GetValue() << std::endl;
            break;
        case 'x':
            std::cout << "�� ��������!" << std::endl;
            return 0;
        default:
            std::cout << "�������� �������. ���������� ��� ���." << std::endl;
        }
    }

    return 0;
}
