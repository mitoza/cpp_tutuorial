#include <iostream>

using namespace std;

// Class declaration
class Rectangle {
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
private:
  int length;
  int breadth;
protected:
};

int main(int argc, char** argv) {

  cout << "C++ Scope Resolution" << endl;

  Rectangle r(10,10);
  cout << "Area: " << r.area() << endl;
  if (r.isSquare()) {
    cout << "Rectangle is square." << endl;
  }

  return 0;
}

Rectangle::Rectangle(int length=1, int breadth=1) {
  this->length = length;
  this->breadth = breadth;
}

Rectangle::Rectangle(Rectangle &r) {
  length = r.length;
  breadth = r.breadth;
}

Rectangle::~Rectangle() {
  cout << "Rectangle Destroyed" << endl;
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


