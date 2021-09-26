// main.cpp
#include <iostream>
#include <cstring>

using namespace std;

int maxNum(int a, int b) {
    if (a>b) return a;
    else return b;
}

string signOfNumber(int n) {
    if (n>=0) return "positive";
    else return "negative";
}

string oddOrEven(int n) {
    if (n % 2 == 0) return "even";
    else "odd";
}

int maxNum(int a, int b, int c) {
    if (a>=b && a>=c) return a;
    else if (b>=a && b>=c) return b;
    else return c;
}

int main(int argc, char** argv) {

    cout << "C++ Conditional Statements" << endl;

    /*
    if (
        <condition: (true|false)>
        <relational operators: (<, <=, >, >=, ==, !=)>
        <logical operators: &&, ||>
    ) {
        // code when true
    } else {
        // code when false
    }
    */
    int a, b;

    cout << "Enter number A: ";
    cin >> a;
    cout << "Enter number B: ";
    cin >> b;

    // Find max of two numbers
    cout << "Max number of " << a << " and " << b <<" is " << maxNum(a,b) << endl;

    // Positive or Negative number
    //cout << "Number " << a << " is " << signOfNumber(a) << " and " << b << " is " << signOfNumber(b) << endl;

    // Number is Odd or Even
    //cout << "Number " << a << " is " << oddOrEven(a) << " and " << b << " is " << oddOrEven(b) << endl;

    // Divide by zero validation
    if (b==0) cout << "a/b get Division by Zero" << endl;
    else cout << a << "/" << b << "=" << (a/b) << " mod " << (a%b) << endl;


    return 0;
}
