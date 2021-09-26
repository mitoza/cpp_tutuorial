// main.cpp
#include <iostream>

using namespace std;

// Function template
template<class T, class C>
T maximum(T a, C b) {
  return a>b?a:b;
}

class StackException;

// Template Class
template<class T>
class Stack {
private:
  T *items;
  int top;
  int size;
public:
  Stack(int size) {
    top = -1;
    this->size = size;
    items = new T[size];
  }
  void push(T item);
  T pop();
  void display();
};

template<class T>
void Stack<T>::display() {
    cout << "Stack: ";
    if (top == -1) {
      cout << "empty";
      return;
    }
    for(int i=0; i<=top; i++) {
        cout << items[i];
        if (i < top) cout << ",";
    }
    cout << endl;
  }

template<class T>
void Stack<T>::push(T item) {
  if (top == size - 1) throw StackException("Stack is full");
  top++;
  items[top] = item;
}

template<class T>
T Stack<T>::pop() {
  if (top == -1) throw StackException("Stack is empty");
  T val = items[top];
  items[top] = 0;
  top--;
  return val;
}

class StackException: exception {
private:
  char *msg;
public:
  StackException(char* msg) {
    this->msg = msg;
  }
  char* what() {
    return msg;
  }
  friend ostream & operator<<(ostream &out, StackException &ex);
};

ostream & operator<<(ostream &out, StackException &ex) {
  out << "StackException: " << ex.msg;
  return out;
}

int main(int argc, char** argv) {

  cout << "C++ Template" << endl;

  cout << "Max: " << maximum(5, 8.6f) << endl;

  try {
    Stack<int> s(4);

    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.display();

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    s.display();
  } catch (StackException ex) {
    cout << ex << endl;
  }

  return 0;
}
