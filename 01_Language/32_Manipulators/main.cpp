// main.cpp
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

  cout << "C++ Manipulators - use it to format strings" << endl;

  cout << endl;
  cout << '\n';

  // Integer: bin, hex, oct, dec
  cout << "hex(163): " << hex << 163 << endl; // a3
  cout << "oct(163): " << oct << 163 << endl; // 243
  cout << "dec(163): " << dec << 163 << endl; // 163

  // Float
  cout << "Pi: " << fixed << 3.1425 << endl;
  cout << "Pi: " << scientific << 3.1425 << endl;

  // Other
  // Data
  //cout << "Set(10): " << set(10) << "Hello" << endl;
  // Left alignment
  // Right alignment
  // WS
  //cout << 10 << ws << 20 << endl;



  return 0;
}
