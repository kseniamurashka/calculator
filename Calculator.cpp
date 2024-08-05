#include "cstdlib"
#include "algorithm"
#include "Calculator.h"

using namespace std;

Calculator::Calculator(string str) {
    while (find(str.begin(), str.end(), ' ') != str.end()) {
        str.erase (find(str.begin(), str.end(), ' '));
    }
    str = str + " ";
    readStr(str);
    if (count_of_brackets % 2) throw std::runtime_error("Skipped separator or parentheses mismatched");

    while (!st_of_op.empty()) {
        q_of_res.push(st_of_op.top());
        st_of_op.pop();
    }
}

bool is_number(const std::string& s)
{
    try
    {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}
double Calculator::count_expr() {
    queue<string> local_q_of_res = q_of_res;
    vector<string> v;
    while (!local_q_of_res.empty()) {
        if (local_q_of_res.front() != ")" && local_q_of_res.front() != "(") {
            v.push_back(local_q_of_res.front());
        }
        local_q_of_res.pop();
    }
    stack<double> locals;
    for (int i = 0; i < v.size(); i++) {
        if (is_number(v[i])) {
            locals.push(stod(v[i]));
        }
        else if (v[i] == "e") {
            locals.push(exp_(1));
        }
        else {
            double last;
            if (locals.empty() && (v[i] == "^")) {
                last = 1.;
            }
            else if (locals.empty() && (v[i] == "+" || v[i] == "-" || v[i] == "~")) {
                last = 0.;
            }
            else {
                last = locals.top();
            }
            locals.pop();

            if (bin_operators.find(v[i]) != string::npos || v[i] == "root") {
                if (locals.empty() && v[i] == "root") throw std::runtime_error("Sytnax error in number of arguments");
                double tmp = locals.top();
                locals.pop();
                locals.push(execute_bin_operation(v[i], tmp, last));
            }
            else {
                locals.push(execute_uno_operation(v[i], last));
            }
        }
    }
    return locals.top();
}

int Calculator::priority(string op1) {
    if (op1 == "-" || op1 == "+") {
        return 1;
    }
    if (op1 == "*" || op1 == "/") {
        return 2;
    }
    if  (op1 == "^" || op1 == "root" || std::find(uno_operators.begin(), uno_operators.end(), op1) != std::end(uno_operators)){
        return 3;
    }
    if (op1 == "~") {
        return 4;
    }
    if (op1 == "(") {
        return 0;
    }
    return -1;
}

void Calculator::sort_station(const string& op){
    if (op == "root") {
        st_of_op.push(op);
    }
    else if (op == ",") {
        while (!st_of_op.empty() && st_of_op.top() != "(") {
            q_of_res.push(st_of_op.top());
            st_of_op.pop();
        }
    }
    else if (op == "(") {
        count_of_brackets++;
        st_of_op.push(op);
    }
    else if (op == ")") {
        count_of_brackets++;
        bool pe = (!st_of_op.empty() && st_of_op.top() == "(");
        while (!st_of_op.empty() && st_of_op.top() != "(") {
            q_of_res.push(st_of_op.top());
            st_of_op.pop();
            if (!st_of_op.empty() && st_of_op.top() == "(") pe = true;
        }
        if (!pe) throw std::runtime_error("Skipped separator or parentheses mismatched");
        st_of_op.pop();
    }
    else if (bin_operators.find(op) != string::npos || std::find(uno_operators.begin(), uno_operators.end(), op) != std::end(uno_operators)) {
        while (!st_of_op.empty() && priority(st_of_op.top()) >= priority(op)) {
            q_of_res.push(st_of_op.top());
            st_of_op.pop();
        }
        st_of_op.push(op);
    }
}

void Calculator::readStr(const string& str) {
    double num = 0;
    int mantissa_length = 0;
    bool previous_op = false;

    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == '.') {
            mantissa_length = 1;
            continue;
        } else if (str[i] == 'e' && str.substr(i, 3) != "exp") {
            q_of_res.push("e");
            previous_op = false;
            continue;
        }
        if ((bin_operators.find(str[i]) != string::npos && bin_operators.find(str[i + 1]) != string::npos && str[i + 1] != '-') || (str[i] == '-' && str[i + 1] == '-')) throw runtime_error("Syntax error: double binary operator");
        if (bin_operators.find(str[i]) != string::npos && str[i] != '-' && (i == 0 || str[i - 1] == '(' )) throw runtime_error("Sytnax error in number of arguments");
        if (str[i] == '-' && (i == 0 || (i > 0 && previous_op) || str[i - 1] == ',')) {
            sort_station("~");
        } else if (isdigit(str[i])) {
            if (isdigit(str[i + 1]) || str[i + 1] == '.') {
                num = (mantissa_length == 0) ? (num * 10 + (str[i] - '0')) : (num + (1 / degree(10, mantissa_length)) * (str[i] - '0'));
                if (mantissa_length > 0) {
                    mantissa_length++;
                }
            } else if (!isdigit(str[i + 1]) && str[i + 1] != '.') {
                num = (mantissa_length == 0) ? (num * 10 + (str[i] - '0')) : (num + (1 / degree(10, mantissa_length)) * (str[i] - '0'));
                q_of_res.push(to_string(num));
                num = 0;
                mantissa_length = 0;
            }
            previous_op = false;
        } else if (str.substr(i, 4) == "root") {
            sort_station("root");
            i += 3;
            if (str[i + 1] != '(') throw std::runtime_error("Skipped separator or parentheses mismatched");
            previous_op = true;
        } else if (bin_operators.find(str[i]) != string::npos || str[i] == '(' || str[i] == ')') {
            if (str[i] != ')') previous_op = true;
            string op;
            op.push_back(str[i]);
            sort_station(op);
        } else {
            int len = 2;
            bool undefined = true;
            while (len <= 5) {
                if (std::find(uno_operators.begin(), uno_operators.end(), str.substr(i, len)) != std::end(uno_operators)) {
                    undefined = false;
                    sort_station(str.substr(i, len));
                    i += (len - 1);
                    if (str[i + 1] != '(') throw std::runtime_error("Skipped separator or parentheses mismatched");
                    previous_op = true;
                    break;
                }
                len++;
            }
            if (undefined) throw std::runtime_error("Undefined function name");
        }
    }

}

double Calculator::execute_uno_operation(const string& op, double first) {
    if (op == "sin") return sin(first);
    if (op == "cos") return cos(first);
    if (op == "tg") return tg(first);
    if (op == "ctg") return ctg(first);
    if (op == "asin") return asin(first);
    if (op == "acos") return acos(first);
    if (op == "atg") return atg(first);
    if (op == "actg") return actg(first);
    if (op == "lnn") return lnn(first);
    if (op == "log2n") return log2n(first);
    if (op == "lgn") return lgn(first);
    if (op == "~") return -first;
    return 0.;
}
double Calculator::execute_bin_operation(const string& op, double first, double second) {
    if (op == "+") return first + second;
    if (op == "-") return first - second;
    if (op == "*") return first * second;
    if (op == "/") return first / second;
    if (op == "^") return degree(first, second);
    if (op == "root") return radical(first, second);
    return 0.;
}

double Calculator::exp_(double a) {
    double an = 1;
    double res = 1;
    int k = 1;
    do {
        an *= a/k;
        res += an;
        k++;
    } while (an > eps || an < -eps);
    return res;
}

double Calculator::degree(double a, double d) {
    if (a == 0) {
        return 0;
    }
    if (a < 0 && (int)(d) == d) {
        int k = (int)d % 2 == 0 ? 1 : -1;
        return k * exp_(d * lnn(-a));
    }
    if (a < 0 && (int)(d) != d) {
        throw std::invalid_argument("Invalid argument for operation '^': negative value in fractional degree");
    }
    return exp_(d * lnn(a));
}

double Calculator::radical(double a, double rootDeg) {
    if ((int)(rootDeg) != rootDeg) throw std::invalid_argument("Invalid argument for root: fractional degree");
    if ((int)(rootDeg) == rootDeg && (int)(rootDeg) % 2 == 0 && a < 0) {
        throw std::invalid_argument("Invalid arguments for root: absolute root's degree for negative value");
    }
    if (rootDeg < 0) throw std::invalid_argument("Invalid argument for root: negative root's degree");
    if ((int)(rootDeg) == rootDeg && (int)(rootDeg) % 2 != 0 && a < 0) {
        return -degree(-a, 1 / rootDeg);
    }
    return degree(a, 1 / rootDeg);
}

double fact (int n) {
    return n == 0 ? 1.0 : n*fact(n - 1);
}

double Calculator::cos(double x) {
    int k = 1;
    double res = 1;
    double an = 1;
    x=x-int(x/(2*M_PI))*(2*M_PI);
    do {
        an *= -x*x/(2*k*(2*k - 1));
        res += an;
        k++;
    } while (an > eps || an < -eps);
    return res;
}

double Calculator::sin(double x) {
    int k = 1;
    x=x-int(x/(2*M_PI))*(2*M_PI);
    double res = x;
    double an = x;

    do {
        an *= -x*x/(2*k*(2*k + 1));
        res += an;
        k++;
    } while (an > eps || an < -eps);
    return res;
}

double Calculator::tg(double x) {
    return sin(x) / cos(x);
}
double Calculator::ctg(double x) {
    return cos(x) / sin(x);
}


double Calculator::asin(double x) {
    if (x > 1 || x < -1) throw std::invalid_argument("Invalid argument for asin: not in [-1, 1]");
    
    int k = 1;
    double res = x;
    double an = x;
    do {
        an *= (x*x)*(2*k*(2*k - 1)) / (4*k*k);
        res += an/((2*k + 1));
        k++;
    } while (an > eps || an < -eps);
    return res;
}
double Calculator::acos(double x) {
    if (x > 1 || x < -1) throw std::invalid_argument("Invalid argument for acos: not in [-1, 1]");

    return M_PI/2 - asin(x);
}
double Calculator::atg(double x) {
    return acos(1/radical(x*x + 1, 2));
}
double Calculator::actg(double x) {
    return M_PI/2 - atg(x);
}


double Calculator::lnn(double num) {
    if (num <= 0) throw std::invalid_argument("Invalid argument for lnn: less or equal 0");

    double x = num;
    int A = 0;
    while (x >= 2)
    {
        A++;
        x /= exp_(1);
    }

    int k = 1;
    double an = x - 1;
    double res = x - 1;
    do {
        an *= -(x - 1);
        res += an/(k + 1);
        k++;
    } while (an > eps || an < -eps);
    return A + res;
}
double Calculator::log2n(double num) {
    if (num <= 0) throw std::invalid_argument("Invalid argument for log2n: less or equal 0");

    return lnn(num) / lnn(2);
}
double Calculator::lgn(double num) {
    if (num <= 0) throw std::invalid_argument("Invalid argument for lgn: less or equal 0");

    return lnn(num) / lnn(10);
}



