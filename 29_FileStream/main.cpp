// main.cpp
#include <iostream>
#include <fstream>

using namespace std;

void writeFile() {
  // Modes:
  // ios::app - append file
  // ios::trunc - truncate file

  ofstream ofs;
  ofs.write("my.txt", ios::trunc);
  ofs << "Hello world" << endl;
  ofs << 25 << endl;
  ofs.close();
}

void readFile() {
  // Modes:
  // ios::in - reading
  // ios::out - writing

  ifstream ifs;
  ifs.open("my.txt", ios::out); // file must be existing
  if (!ifs.is_open()) {
    cout << "File not exists" << endl;
    return;
  }
  string s;
  int x;
  getline(ifs, s);
  ifs >> x;
  cout << s << endl << x << endl;
  if (ifs.eof()) {
    cout << "EndOfFile" << endl;
  }

  ifs.close();
}

int main(int argc, char** argv) {

  cout << "C++ Stream - flow of data" << endl;

  writeFile();
  readFile();

  return 0;
}
