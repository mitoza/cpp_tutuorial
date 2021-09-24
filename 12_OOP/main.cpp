#include <iostream>

using namespace std;

/*
 * Object-oriented programming - is a strategy or methodology of developing software
 * Other methodology: Structured programming, Procedural programming, Modular programming, Aspect-oriented programming

 * Principles of object-oriented:
 * 1. Abstraction - using functions and doesn't know how they work
 * 2. Encapsulation: data hiding - we can see functions of class but we can't see the data
 * 3. Inheritance - one class can use properties of another class and modify them
 * 4. Polymorphism - we can use properties of parent class from child class

 Class - definition and Object - instance
*/

// Class declaration
class Rectangle {
private:
  int length;
  int breadth;

public:
// Constructors
// 1. Default constructor
  // Rectangle() {}

// 2. Non-parameterized
  // Rectangle() {
  //   length = 1;
  //   breadth = 1;
  // }

// 3. Parameterized
  Rectangle(int l=1, int b=1) {
    setLength(l);
    setBreadth(b);
  }

// 4. Shallow Copy constructor
  Rectangle(Rectangle &r) {
    length = r.length;
    breadth = r.breadth;
  }

// Property functions
  void setLength(int l) { // Mutator
    if (l <= 0) l = 1;
    length = l;
  }

  int getLength() { // Accessor
    return length;
  }

  void setBreadth(int b) { // Mutator
    if (b <= 0) b = 1;
    breadth = b;
  }

  int getBreadth() { // Accessor
    return breadth;
  }

// Class Functions
// Facilitators
  int area() {
    return length * breadth;
  }

  int perimeter() {
    return 2 * (length + breadth);
  }

// Enquiry
  int isSquare() {
    return length == breadth;
  }

// Destructor
  ~Rectangle() {
  }

};

// Deep Copy Constructor
class copyClass {
private:
  int a;
  int *p;
public:
  copyClass(int x) {
    a = x;
    p = new int[a];
  }

  copyClass(copyClass &c) {
    a = c.a;
    p = new int[a]; // <-- allocate new memory for copyClass.p
    // TODO Write all values from c.p to p
  }

  ~copyClass() { // Destructor
    delete []p;
  }
};

int main(int argc, char** argv) {

  cout << "C++ Object-oriented programming" << endl;

  // Declaration an object
  Rectangle r; // Create an object in Stack
  r.setLength(-5);
  r.setBreadth(10);
  cout << "Area: " << r.area() << endl;

  // Pointer on Object
  Rectangle *p; // Create pointer in Stack
  p = &r;
  cout << "Perimeter: " << p->perimeter() << endl;

  // Create Object in Heep using Pointer
  Rectangle *q; // Initialization
  q = new Rectangle; // Declaration
  q->setLength(2);
  q->setBreadth(-3);
  cout << "Rectangle area: " << q->area() << ", perimeter: " << q->perimeter() << endl;
  delete q;

  // Constructors
  Rectangle recDefaultConstructor;
  Rectangle recNonParamConstructor();
  Rectangle recParamConstructor(5,10);
  Rectangle copyConstructor(recParamConstructor);


  return 0;
}
