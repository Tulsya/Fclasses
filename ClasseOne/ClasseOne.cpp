#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>

class Calculator
{
private:
    double _num1;
    double _num2;
public:
    Calculator(double num1, double num2);
    double Add() const;
    double multiply() const;
    double subtract_1_2() const;
    double subtract_2_1() const;
    double divide_1_2() const;
    double divide_2_1() const;
    bool set_num1(double num1);
    bool set_num2(double num2);
};

Calculator::Calculator(double num1, double num2) : _num1(num1), _num2(num2) {}

double Calculator::Add() const {
    return _num1 + _num2;
}

double Calculator::multiply() const {
    return _num1 * _num2;
}

double Calculator::subtract_1_2() const {
    return _num1 - _num2;
}

double Calculator::subtract_2_1() const {
    return _num2 - _num1;
}

double Calculator::divide_1_2() const {
    return _num1 / _num2;
}

double Calculator::divide_2_1() const {
    return _num2 / _num1;
}

bool Calculator::set_num1(double num1) {
    if (num1 == 0)
    {
        return false;
    }
    _num1 = num1;
    return true;
}

bool Calculator::set_num2(double num2) {
    if (num2 == 0)
    {
        return false;
    }
    _num2 = num2;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    std::system("chcp 1251");
    Calculator calc(0, 0);

    while (true) {
        double num1, num2;
        std::cout << "Введите num1: ";
        std::cin >> num1;
        bool valid_input = calc.set_num1(num1);
        if (!valid_input) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "Введите num2: ";
        std::cin >> num2;
        valid_input = calc.set_num2(num2);
        if (!valid_input) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "num1 + num2 = " << calc.Add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}
