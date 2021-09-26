// main.cpp
#include <iostream>
#include <cstring> // string.h - char string
#include <string> // - class string

using namespace std;

void charStrings() {
  char x = 'A';
  char s1[50] = "Hello";
  char s2[] = " world";
  char s3[] = {'H','e','l','l','o','\0',' ','w','o','r','l','d'};
  char s4[] = {65,66,67,68,'\0'};
  char s5[] = "wo";
  cout << s3 << endl; // will write "Hello"
  char s[50];
  cout << "Enter your name: ";
  cin.getline(s, 50);
  cout << "Your name is: " << s << endl;

  // Length of string till '\0'
  cout << "Length of your name: " << strlen(s) << endl;

  // String concatination
  cout << strcat(s1, s2) << endl; // Add s2 to s1
  cout << strncat(s1, s2, 4) << endl; // Add s2 to s1

  // Copy string
  char s6[50];
  //strcpy(s6, s1);
  strncpy(s6, s1, 20);
  cout << "Copy: "<< s6 << endl;

  // Find substring
  if (strstr(s1, s5) != NULL) { // cout can't write NULL
    cout << "Substring: "<< strstr(s1, s5) << endl;
  }
  cout << "Substring char: " << strchr(s1, 'w') << endl;
  cout << "Substring char from right: " << strrchr(s1, 'w') << endl;

  // Comparing strings, return {-1, 0, 1}
  char str1[] = "Hello";
  char str2[] = "HellO";
  cout << "Compare: "<< strcmp(str1, str2) << endl;

  // Tokeniser and To integer
  char text[20] = "x=10;y=20;z=30";
  char *token=strtok(text, "=;");

  while(token != NULL) {
    cout << token << " ";
    token = strtok(NULL, "=;");
  }
  cout << endl;

  cout << "a: " << (int)'a' << ", A: " << (int)'A' << endl;

}

void showStringInfo(string &str) {
  // Check if Empty
  if (str.empty()) {
    cout << "String is empty. " <<
      "Length: " << str.length() << // Length
      ", capacity: " << str.capacity() << // Capacity
    endl;
    return;
  }
  cout << "String: " << str <<
    ", length: " << str.length() << // Length
    ", size:" << str.size() << // Size
    ", capacity: " << str.capacity() << // Capacity
    ", max size: " << str.max_size() << // Max size
  endl;
}

void stringClass() {
  string str; // - object that have a length(size) and capacity

  // GetLine
  cout << "Enter your name: ";
  std::getline(cin, str);
  showStringInfo(str);

  // Resize string
  cout << "Resize to 30. ";
  str.resize(30);
  showStringInfo(str);

  // Clear string
  str.clear();
  cout << "Clear string. ";
  showStringInfo(str);

  // Append or +
  str.append("Helloworld");
  cout << "Append. ";
  showStringInfo(str);

  // Insert
  cout << "Insert. ";
  str.insert(5, " ");
  showStringInfo(str);

  // Replace
  cout << "Replace. ";
  str.replace(5, 2, " W");
  showStringInfo(str);

  // Replace
  cout << "Erase. ";
  str.erase(); // The same as clear()
  showStringInfo(str);

  str = "Hello world";

  // Push back
  cout << "Push back. ";
  str.push_back('Z');
  showStringInfo(str);

  // Pop back
  cout << "Pop back. ";
  str.pop_back();
  showStringInfo(str);

  // Swap
  string s2 = "World hello";
  str.swap(s2); // Swap two strings value
  cout << "Swap. ";
  showStringInfo(s2);

  // Copy
  char dest[] = "Hello";
  str.copy(dest, str.length());
  cout << "Copy. Dest: " << dest << endl;

  // Find
  cout << "Find. " << str.find("l") << ", " << str.find('l') << endl;
  cout << "Right Find. " << str.rfind("l") << endl;
  cout << "Find first of. " << str.find_first_of("le") << endl; // Will find l or e
  cout << "Find first of from 4. " << str.find_first_of("le", 4) << endl; // Will find l or e
  cout << "Find last of. " << str.find_last_of("le") << endl; // Will find l or e

  // Substring
  cout << "Sub string. " << str.substr(2,5) << endl;

}

void stringClassCompare() {
  // Compare
  string s1 = "Hello";
  string s2 = "Hello";
  cout << "Compare. " << s1.compare(s2) << endl; // result 0 - equal

  s2 = "World";
  cout << "Compare. " << s1.compare(s2) << endl; // result -1 - s1 is lower

  s2 = "HellO";
  cout << "Compare. " << s1.compare(s2) << endl; // result 1 - s1 is higher

  // At
  cout << "At[4]: " << s1.at(4) << " or " << s1[4] << endl;

  // Front
  cout << "Front: " << s1.front() << " or " << s1[0] << endl;

  // Back
  cout << "Back: " << s1.back() << " or " << s1[s1.length()-1] << endl;

  // String concatination
  cout << "Concationation: " << s1+s2 << endl;

}

void stringClassIterator() {
  string str = "today";

  // String iterator
  string::iterator it;
  for(it = str.begin(); it != str.end(); it++) {
    *it = *it - 32; // Uppercase
  }
  cout << str << endl;

  for(it = str.end()-1; it>=str.begin(); it--) {
    cout << *it;
  }
  cout << endl;

  // String reverse iterator
  string::reverse_iterator rit;
  for(rit = str.rbegin(); rit!=str.rend(); rit++) {
    cout << *rit;
  }
  cout << endl;

  // String iterator
  for(int i=0; str[i]!='\0'; i++) {
      str[i] += 32;
  }
  cout << str << endl;

}

int main(int argc, char** argv) {

  cout << "C++ String" << endl;

  //charStrings();

  //stringClass();

  //stringClassCompare();

  stringClassIterator();

  return 0;
}
