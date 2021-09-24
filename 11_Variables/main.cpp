#include <iostream>

using namespace std;

// Global variable allocated in Code memory, can be access from every part of the code
int g = 10;
int y = 10;

void funcG(int a) { // Local variable allocated in Stack memory
  int b = 10; // Local variable allocated in Stack memory
  {
    int g = 10; // Local variable allocated in Stack memory
    g = g + ::g; // Access to Global variable
    cout << "G2: " << g << endl;
  }
  g = g + a + b;
}

// Scope Rule
void funcY() {
  int y = 20;
  {
    int y = 30;
    cout << "Y1: " << y << endl;
  }
  cout << "Y2: " << y << endl;
}

// Static Variable
void funcV() {
  static int v = 0; // Static variable allocated in Code memory, can be access only from function
  int a = 5;
  v++;
  cout << "A: " << a << ", V: " << v << endl;
}


int main(int argc, char** argv) {

    cout << "C++ Variables" << endl;

    // Global variable g
    cout << "G1: " << g << endl;
    int x = 10; // Local variable allocated in Stack memory
    funcG(x);
    cout << "G3: " << g << endl;


    // Scoping Rule for y
    funcY();
    cout << "Y3: " << y << endl;


    // Static variables
    funcV();
    funcV();
    funcV();



    return 0;
}
