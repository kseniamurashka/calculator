#include <gtest/gtest.h>
#include "Calculator.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class BinOperators: public testing::Test
{
protected:
    string add_str = "5 + 4.578";
    string subtr_str = "5 - 2.3456";
    string multipl_str = "3 * 9.89";
    string div_str = "78 / 745.8";
};

class TrigonomFunctions: public testing::Test
{
protected:
    string sin_str1 = "sin(123)";
    string cos_str1 = "cos(123)";
    string tg_str1 = "tg(123)";
    string ctg_str1 = "ctg(123)";

    string asin_str1 = "asin(0.123)";
    string asin_str2 = "asin(1.123)";

    string acos_str1 = "acos(0.123)";
    string acos_str2 = "acos(1.123)";
    
    string atg_str = "atg(123)";
    string actg_str = "actg(123)";
};

class LogFunctions: public testing::Test
{
protected:
    string lnn_str1 = "lnn(123)";
    string lnn_str2 = "lnn(-123)";
    string log2n_str1 = "log2n(123)";
    string log2n_str2 = "log2n(-123)";
    string lgn_str1 = "lgn(123)";
    string lgn_str2 = "lgn(-123)";
};

class Degree: public testing::Test
{
protected:
    string str1 = "12^3";
    string str2 = "12.3^4";
    string str3 = "2^(3.4)";
    string str4 = "12^(-3.4)";
    string str5 = "-5^3";
    
    string str6 = "(-2)^(0.24)";

    string str7 = "-(2^(0.24))";
};

class Root: public testing::Test
{
protected:
    string str1 = "root(123, 4)";
    string str2 = "root(123.4, 5)";
    string str3 = "root(-123, 3)";

    string str4 = "root(123, -4)";
    string str5 = "root(-123, 2)";
    string str6 = "root(123, 2.34)";
};

class SeparatorsParenthesesTests: public testing::Test
{
protected:
    string str1 = "(1 + 2) * 3";
    string str2 = "(1 + 2)*(3 + 4)";
    string str3 = "sin(1 + root(8, 2))";
    string str4 = "sin(12)*(1 + 2)";
    string str5 = "(1 + 7 * (2 + (5 + 6) * (7 / 8)))";

    vector<std::string> exceptions = {"(1 + 2", "1 + 2)", ") 1 + 2", "sin(1 + 2", "root(56, 2", "sin3"};
};

class RepeatBinOp: public testing::Test
{
protected:
    string str1 = "-(-5) - (-3 + 1)";
    string str2 = "1 + -8";
    string str3 = "3 * -9";
    string str4 = "25 / -5";
    vector<std::string> exceptions_minus = {"--2 + 3", "1 -- 2", "sin(--1)", "(--7 + 8)"};
    vector<std::string> exceptions_plus = {"++2 + 3", "1 ++ 2", "sin(++1)", "(++7 + 8)"};
    vector<std::string> exceptions_mult = {"**2 + 3", "1 ** 2", "sin(**1)", "(**7 + 8)"};
    vector<std::string> exceptions_div = {"//2 + 3", "1 // 2", "sin(//1)", "(//7 + 8)"};

    vector<std::string> exceptions_other_combinations = {"9 -+ 8", "1 -* 7", "3 - *8", "1 ++ -8", "3 * -- 9", "1+-*/9"};
};

class NumberOfArguments: public testing::Test
{
protected:
    string str1 = "-9 + 8";
    string str2 = "(-9 + 8)";

    vector<std::string> exceptions = {"+9 - 8", "(+9 - 8)", "root(123)"};
};

class UndefinedFunctions: public testing::Test
{
protected:
    vector<std::string> exceptions = {"sim(89)", "cod(78)", "3 + th(8)", "actf(78)", "log3n(0) * 78", "!2 + 3"};
};
//count of arguments root(9, 1, 2), sin(8, 9)
//sin(1.0.123)
