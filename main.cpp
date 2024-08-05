#include <iostream>
#include "Calculator.h"

using namespace std;

int main(int argc, char* argv[]) {
    string s;
    std::getline(std::cin, s);
    try {
        Calculator calc(s);
        double res = calc.count_expr();
        cout << res << endl;
    }
    catch (std::exception const & err) {
        cout << err.what();
        exit(-1);
    }
    return 0;
}
