#include <iostream>
#include <cstring> // string.h

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

  // String concatinating
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

}

void stringClass() {

}


int main(int argc, char** argv) {

  cout << "C++ String" << endl;

  charStrings();

  stringClass();

  return 0;
}
