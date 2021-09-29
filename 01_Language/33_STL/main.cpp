// main.cpp
#include <iostream>
#include <list>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>


using namespace std;

void listFunc() {
    list<int> l = {10,25,30,90};

    cout << "List Foreach: ";
    for(int x: l) {
        cout << x << ", ";
    }
    cout << endl;

    l.push_back(70);
    l.push_back(25);
    l.pop_back();

    cout << "List Iterator: ";
    list<int>::iterator itr;
    for(itr = l.begin(); itr != l.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << endl;
}

void forwardListFunc() {
    forward_list<int> l = {15,30,40,50};

    cout << "ForwardList Foreach: ";
    for(int x: l) {
        cout << x << ", ";
    }
    cout << endl;

    l.push_front(60);
    l.push_front(70);
    l.pop_front();

    cout << "ForwardList Iterator: ";
    forward_list<int>::iterator itr;
    for(itr = l.begin(); itr != l.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << endl;
}

void vectorFunc() {
    vector<int> v = {9,19,24,54};

    cout << "Vector Foreach: ";
    for(int x: v) {
        cout << x << ", ";
    }
    cout << endl;

    v.push_back(39);
    v.push_back(10);
    v.pop_back();

    cout << "Vector Iterator: ";
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << endl;

    cout << "Vector Change Values: ";
    for(itr = v.begin(); itr != v.end(); itr++) {
        cout << ++*itr << ", ";
    }
    cout << endl;

}

void setFunc() {
    set<int> s = {19,12,13,76};

    cout << "Set Foreach: ";
    for(int x: s) {
        cout << x << ", ";
    }
    cout << endl;

    s.insert(9);
    s.insert(2);

    cout << "Set Iterator: ";
    set<int>::iterator itr;
    for(itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << endl;
}

void mapFunc() {
    map<int, string> m;

    m.insert(pair<int, string>(1, "John"));
    m.insert(pair<int, string>(2, "Smith"));
    m.insert(pair<int, string>(3, "Keano"));

    map<int, string>::iterator itr;
    cout << "Map Iterator: " << endl;
    for(itr = m.begin(); itr!=m.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }

    itr = m.find(2);
    cout << "Map Find 2:" << itr->first << " " << itr->second << endl;

}

void queueFunc() {
  queue<int> q;// = {19,12,13,76};

  q.push(3);
  q.push(9);
  q.push(7);
  q.push(5);

  cout << "Queue For: ";
  int value;
  while(!q.empty()) {
    cout << q.front() << ", ";
    q.pop();
  }
  cout << endl;

}

class Student {
public:
  string name;
  int age;
  Student(string name, int age) {
    this->name = name;
    this->age = age;
  }
  friend ostream & operator<<(ostream &os, Student &item);
};

ostream & operator<<(ostream &os, Student &item) {
  os << item.name << ", " << item.age;
  return os;
}

int main(int argc, char** argv) {

  cout << "C++ STL(Standard Template Library) collection of classes" << endl;

  // Algorithms:
  // search()
  // binary-search()
  // reverse()
  // concat()
  // copy()
  // union()
  // intersection()
  // merge()
  // heap()

  // DataStructure. Containers(templates):
  // vector() - push_back(), pop_back(), insert(), remove(), size(), empty()
  // list() - same as vector(), push_front(), pop_front(), front(), back()
  // forward-list() - single list
  // dequeue() - same as vector() but with data shift
  // priority-queue - heap data structure. push(), pop(), empty(), size(). Will work with larger element
  // stack() LIFO (Last In First Out). push(), pop(), empty(), size()
  // set() - will contain only unique elements
  // multiset() - as set but allow dublicate elements
  // map(<key, value>) - will contain HashTable
  // multimap(<key, value>) - allow dublicate key

  // Iterators:

  listFunc();
  cout << "->" << endl;

  forwardListFunc();
  cout << "->" << endl;

  vectorFunc();
  cout << "->" << endl;

  setFunc();
  cout << "->" << endl;

  mapFunc();
  cout << "->" << endl;

  vector<Student *> v;
  v.push_back(new Student("John", 15));
  v.push_back(new Student("Villie", 13));
  v.push_back(new Student("Sam", 14));

  vector<Student *>::iterator v_itr;
  for(v_itr=v.begin(); v_itr!=v.end(); v_itr++) {
    cout << "Student: " << **v_itr << endl;
  }
  cout << "->" << endl;

  queueFunc();
  cout << "->" << endl;


  return 0;
}
