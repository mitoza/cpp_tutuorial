#include <iostream>

using namespace std;

// Class declaration
class Rectangle {
private:
  int length;
  int breadth;

public:
  // Constructors
  Rectangle();
  Rectangle(int l, int b);
  Rectangle(Rectangle &r);
  // Accessors
  int getLength() { return length; }
  int getBreadth() { return breadth; }
  // Mutators
  void setLength(int l);
  void setBreadth(int b);
  // Facilitators
  int area();
  int perimeter();
  // Enquiry
  bool isSquare();
  // Destructor
  ~Rectangle();

};

int main(int argc, char** argv) {

  cout << "C++ Scope Resolution" << endl;

  Rectangle r(10,5);
  cout << "Area: " << r.area() << endl;

  return 0;
}

Rectangle::Rectangle(int l=1, int b=1) {
  length = l;
  breadth = b;
}

Rectangle::Rectangle(Rectangle &r) {
  length = r.length;
  breadth = r.breadth;
}

void Rectangle::setLength(int l) {
  if (l<=0) l=1;
  length = l;
}

void Rectangle::setBreadth(int b) {
  if (b<=0) b=1;
  breadth = b;
}

int Rectangle::area() {
  return length * breadth;
}

int Rectangle::perimeter() {
  return 2 * (length + breadth);
}

bool Rectangle::isSquare() {
  return length == breadth;
}

Rectangle::~Rectangle() {
  cout << "Rectangle Destroyed" << endl;
}
