#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
private:
  // InClass Initializer
  int length = 1;
  int breadth = 1;
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
protected:
};

#endif // RECTANGLE_H
