/**
 *  @file Calculator.h
 *  @author Murashka Kseniaa
 *  @brief Заголовочный файл описания калькулятора
 *  @date 03.05.2024
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

//! \brief Класс, реализующий калькулятор
//! \note тест doxygen
class Calculator {
public:
    //! Конструктор с параметрами
    //! \param str преобразуемая строка
    Calculator(std::string str);
    //! Функция подсчета результата выражения
    //! \return результат вычисления 
    double count_expr();
protected:
    double M_PI = 3.1415926535;//!< число pi
    double eps = 1.0e-12;//!< точность вычисления

    //! Функция вычисления степени экспоненты
    //! \param x степень экспоненты
    //! \return результут вычисления функции
    double exp_(double x);
    //! Функция вычисления степени числа
    //! \param a основание степени
    //! \param x степень
    //! \return результут вычисления функции
    double degree (double a, double x);
    //! Функция вычисления корня
    //! \param a подкоренное число
    //! \param x степень корня
    //! \return результут вычисления функции
    double radical (double a, double x);

    //! Функция вычисления косинуса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double cos(double x);
    //! Функция вычисления синуса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double sin(double x);
    //! Функция вычисления тангенса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double tg(double x);
    //! Функция вычисления котангенса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double ctg(double x);

    //! Функция вычисления арккосинуса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double acos(double x);
    //! Функция вычисления арксинуса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double asin(double x);
    //! Функция вычисления арктангенса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double atg(double x);
    //! Функция вычисления арккотангенса
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double actg(double x);

    //! Функция вычисления натурального логарифма
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double lnn(double x);
    //! Функция вычисления двоичного логарифма
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double log2n(double x);
    //! Функция десятичного логарифма
    //! \param x аргумент функции
    //! \return результут вычисления функции
    double lgn(double x);

    std::string bin_operators = ",-+*/^";//!< бинарные операторы
    std::vector<std::string> uno_operators = {"sin", "cos", "tg", "ctg", "acos", "asin", "atg", "actg", "lnn", "log2n", "lgn", "~"};//!< функции и унарный минус
    std::stack<std::string> st_of_op;//!< стек операторов
    std::queue<std::string> q_of_res;//!< очередь результатов
    
    //! Функция определения приоритета операции
    //! \param op1 оператор
    //! \return приоритет
    int priority(std::string op1);
    //! Функция разбора строки на элементы
    //! \param str строка для разбора
    void readStr(const std::string& str);
    //! Функция сортировочной станции
    //! \param op оператор
    void sort_station(const std::string& op);

    //! Функция выполнения унарной операции (вычисление функции или применения унарного минуса)
    //! \param op оператор
    //! \param first аргумент
    //! \return результат выполнения операции
    double execute_uno_operation(const std::string& op, double first);
    //! Функция выполнения бинарной операции
    //! \param op оператор
    //! \param first первый аргумент
    //! \param second второй аргумент
    //! \return результат выполнения операции
    double execute_bin_operation(const std::string& op, double first, double second);

    int count_of_brackets = 0;//!< счетчик скобок
};

// #endif