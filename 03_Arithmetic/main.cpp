// main.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cout << "C++ Arithmetic and Operations" << endl;

    // Arithmetic +, -, *, /, %
    cout << "Arithmetic operations: +, -, *, /, % mod" << endl;

    // Relation operations <, <=, >, >=, ==, !=
    cout << "Relation operations: <, <=, >, >=, ==, !=" << endl;

    // Logical operations &&, ||, !
    cout << "Logical operations: &&, ||, !" << endl;

    // Bitwise operations &, |, ~, ^
    cout << "Bitwise operations: & and, | or, ~ not, ^ x-or" << endl;

    // Increment/Decrement operations ++, --
    cout << "Increment/Decrement operations ++, --" << endl;

    // Operator and Assumed procedure
    cout << "{'(',')'}=3, {'*','/','%'}=2, {'+','-'}=1" << endl;

    // Compound assignment
    // Arithmetic +=, -=, *=, /=, %=
    // Logical &=, |=, <<=, >>=
    cout << "Arithmetic compound assignment: +=, -=, *=, /=, %=" << endl;
    cout << "Logical compound assignment: &=, |=, <<=, >>=" << endl;

    // Overflow
    char x = 127;
    cout << "For char number 127 overflow is: " << (int)++x << endl;


    return 0;
}
