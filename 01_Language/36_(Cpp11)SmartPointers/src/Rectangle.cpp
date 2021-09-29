#include "Rectangle.h"
Rectangle::Rectangle():Rectangle(1,1) { // Delegation of Constructor

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
