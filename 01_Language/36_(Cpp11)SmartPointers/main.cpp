// main.cpp
#include <iostream>
#include <memory>
#include "Rectangle.h"

using namespace std;

void normalPointerProblem() {
  Rectangle *p = new Rectangle(5, 1);
  delete p; // we should declare delete
}

void uniquePointer() {
  unique_ptr<Rectangle> p(new Rectangle(10, 5)); // We cannot share this pointer to other pointer
  cout << "Unique Area: " << p->area() << endl;

  unique_ptr<Rectangle> p2;
  // p2 = p; // - it's not allowed to use sharing
  p2 = move(p); // p - will be removing and p2 will store the address of p value

  // cout << "Unique Area: " << p->area() << endl; // Error will occures
  cout << "Unique Area2: " << p2->area() << endl;


} // unique_ptr p will be deleted

void sharedPointer() {
  shared_ptr<Rectangle> p(new Rectangle()); // will use Reference_counter, use_count()

  shared_ptr<Rectangle> p2 = p;
  cout << "Shared Area: " << p->area() << endl;
  cout << "Shared Area2: " << p2->area() << endl;
  cout << "Shared objects count: " << p.use_count() << endl;


} // shared_ptr p will be deleted

void weakPointer() {
  // Check example at: https://ravesli.com/urok-195-std-weak_ptr-tsiklicheskaya-zavisimost-s-std-shared_ptr/

}
int main(int argc, char** argv) {

  cout << "C++ Smart Pointers" << endl;

  // pointer
  normalPointerProblem();

  // unique_prt
  uniquePointer();

  // shared_ptr
  sharedPointer();

  // weak_ptr
  weakPointer();

  return 0;
}
