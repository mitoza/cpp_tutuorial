#include <iostream>

using namespace std;

class Base {
public:
  int x = 10;

  void show() {
    cout << "X: " << x << endl;
  }
};

class Drive: public Base { // extends Base class
public:
  int y = 15;
  void show2() {
      cout << "X: " << x << ", Y: " << y << endl;
  }
};

class Rectangle {
private:
  int length;
  int breadth;
public:
  Rectangle();
  Rectangle(int length, int breadth);
  Rectangle(Rectangle &r);
  ~Rectangle();
  int getLength() { return length; }
  int getBreadth() { return breadth; }
  void setLength(int length);
  void setBreadth(int breadth);
  int area();
  int perimeter();
  bool isSquare();
  friend ostream & operator<<(ostream &out, Rectangle &r);
};

class Cuboid : public Rectangle {
private:
  int height;
public:
  Cuboid();
  Cuboid(int length, int breadth, int height);
  Cuboid(Cuboid &c);
  ~Cuboid();
  int getHeight() { return height; }
  void setHeight(int height);
  int volume();
  friend ostream & operator<<(ostream &out, Cuboid &c);
};

int main(int argc, char** argv) {

    cout << "C++ Inheritance" << endl;

    // Simple example
    Drive d;
    d.show();
    d.show2();

    // Most efficient way
    Rectangle r(10,15);
    cout << "Rectangle: " << r << endl;

    Cuboid c(1,2,3);
    cout << "Cuboid: " << c << ", Volume: " << c.volume() << endl;

    return 0;
}

// Rectangle implementation
Rectangle::Rectangle() {
  this->length = 1;
  this->breadth = 1;
}

Rectangle::Rectangle(int length=0, int breadth=0) {
  cout << "Constructor of Rectangle" << endl;
  this->length = length;
  this->breadth = breadth;
}

Rectangle::Rectangle(Rectangle &r) {
  this->length = r.length;
  this->breadth = r.breadth;
}

Rectangle::~Rectangle() {
  cout << "Destructor of Rectangle" << endl;
}

void Rectangle::setLength(int length) {
  this->length = length;
}

void Rectangle::setBreadth(int breadth) {
  this->breadth = breadth;
}

int Rectangle::area() {
  return length * breadth;
}

int Rectangle::perimeter() {
  return 2 * (length + breadth);
}

bool Rectangle::isSquare() {
  return length==breadth;
}

ostream & operator<<(ostream &out, Rectangle &r) {
  out << r.length << "," << r.breadth;
  return out;
}

// Cuboid implementation
Cuboid::Cuboid(): Rectangle(1,1) {
  this->height = 1;
}

Cuboid::Cuboid(int length=0, int breadth=0, int height=0): Rectangle(length, breadth) {
  cout << "Constructor of Cuboid" << endl;
  this->height = height;
  setLength(length);
  setBreadth(breadth);
}

Cuboid::~Cuboid() {
  cout << "Destructor of Cuboid" << endl;
}

void Cuboid::setHeight(int height) {
  this->height = height;
}

int Cuboid::volume() {
  return getLength() * getBreadth() * height;
}

ostream & operator<<(ostream &out, Cuboid &c) {
  out << c.getLength() << "," << c.getBreadth() << "," << c.height;
  return out;
}
