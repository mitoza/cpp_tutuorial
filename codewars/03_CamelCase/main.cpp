// main.cpp
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

std::string to_camel_case(std::string text) {
  std::string result;
  for(int i=0; i<(int)text.length(); i++) {
    if (text[i] != '_' && text[i] != '-') {
      result += text[i];
      continue;
    }
    if (i+1 >= (int)text.length()) continue;
    result += toupper(text[i+1]);
    i++;
  }
  return result;
}

int main(int argc, char** argv) {

   cout << "the_stealth_warrior: " << to_camel_case("the_stealth_warrior") << endl; //"theStealthWarrior"));
   cout << "The-Stealth-Warrior: " << to_camel_case("The-Stealth-Warrior") << endl; //"TheStealthWarrior"));


  return 0;
}
