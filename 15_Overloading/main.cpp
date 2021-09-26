// main.cpp
#include <iostream>

using namespace std;

// Class that will work with complex numbers
class Complex {
private:
  float real;
  float imagi;
public:
  Complex(float real = 0.0f, float imagi = 0.0f) {
      this->real = real;
      this->imagi = imagi;
  }

  Complex add(Complex c) {
    Complex result;
    result.real = this->real + c.real;
    result.imagi = this->imagi + c.imagi;
    return result;
  }

  Complex operator+(Complex c) {
    Complex result;
    result.real = this->real + c.real;
    result.imagi = this->imagi + c.imagi;
    return result;
  }

  void display() {
    cout << real << "+" << imagi << "i" << endl;
  }

  // Insertion Overloading Operator
  friend ostream & operator<<(ostream &o, Complex &c);

  // Overloading operator
  friend Complex operator-(Complex c1, Complex c2);
};

int main(int argc, char** argv) {

    cout << "C++ Overloading" << endl;

    // Signs that can be overloading: +, -, *, /, (), ++, --, new, delete, ...

    Complex c1(3,7);
    Complex c2(5,4);
    Complex c3;

    c3=c1.add(c2);
    c3.display();

    c3=c3+c2;
    c3.display();

    c3=c3-c2;
    // Insertion Operator
    cout << c3 << endl;
    operator<<(cout, c2);

    return 0;
}

ostream & operator<<(ostream &out, Complex &c) {
  out << c.real << "+" << c.imagi << "i";
  return out;
}

Complex operator-(Complex c1, Complex c2) {
  Complex result;
  result.real = c1.real - c2.real;
  result.imagi = c1.imagi - c2.imagi;
  return result;
}
