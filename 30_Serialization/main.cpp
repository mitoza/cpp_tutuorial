// main.cpp
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Student {
public:
  string name;
  int roll;
  string branch;
  friend ostream & operator<<(ostream &out, Student &s);
  friend istream & operator>>(istream &in, Student &s);
};

ostream & operator<<(ostream &out, Student &s) {
  out << s.name << endl;
  out << s.roll << endl;
  out << s.branch << endl;
  return out;
}

istream & operator>>(istream &in, Student &s) {
  in >> s.name;
  in >> s.roll;
  in >> s.branch;
  return in;
}

void saveStudent(Student &s, char* filename) {
  ofstream ofs(filename, ios::trunc);
  ofs << s;
  ofs.close();
}

Student * openStudent(char* filename) {
  ifstream ifs(filename, ios::out);
  Student *s = new Student;
  ifs >> *s;
  return s;
}

int main(int argc, char** argv) {

  cout << "C++ Serialozation - storing object into a file" << endl;

  Student s1;
  s1.name = "Mito";
  s1.roll = 122 ;
  s1.branch = "CS";

  saveStudent(s1, "student.txt");

  Student *s2;
  s2 = openStudent("student.txt");
  cout << s2->name << endl;
  cout << s2->roll << endl;
  cout << s2->branch << endl;

  delete s2;


  return 0;
}
