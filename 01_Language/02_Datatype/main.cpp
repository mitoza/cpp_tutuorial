// main.cpp
#include <iostream>
#include <cstring>

using namespace std;

// User defined types
enum Day {MON,TUE=3,WED,THU=5,FRI,SAT,SUN};

typedef Day MyDay;

struct User {
};

union Tree {
};

class Playlist {
private:
public:
  Playlist() {
  }
};

void func() {
}

int main(int argc, char** argv) {

    cout << "C++ Data Types" << endl;

    // Primitive integer variables
    int i = 1; // Size 2 bytes or 4 bytes
    short sh = 13;
    char c = 65; // Size 1 byte
    cout << "Char: " << CHAR_MIN << " " << CHAR_MAX << endl;
    long l;
    cout << "Long: " << LONG_MIN << " " << LONG_MAX << endl;

    // Boolean
    bool b; // Size: unidentify

    // Void
    //void *prt = func();

    // Primitive floating point
    float f = 3.1425f; // Size 4 bytes
    double d = 3.1425; // Size 8 bytes

    // User defined types
    Day day = MON; // enum
    MyDay myday = day; // typedef
    string s; // class string

    // Derived Array variables
    int A[] = {1,2,3};
    int B[2][3] = {{1,2,3}, {4,5,6}};

    // Derived Pointer variables
    int *p = A;

    // Derived Reference variables
    int &y = i; // thin is an another name of variable i and it
    cout << i << endl;
    i++;
    y++;
    cout << i << endl;

    // Type conversion
    bool someBool1 = (bool)i; // method 1
    bool someBool2 = bool(i); // method 2
    bool someBool3 = static_cast<bool>(i); // method 3
    long someLong = i; // Here we don't need type conversion

    cout << "Size of Integer: " << sizeof(i) << endl;

    return 0;
}

/*
 * -------------------------------------------
 * | Type      | Meaning       | Size        |
 * -------------------------------------------
 * | bool      | boolean       | undefined   |
 * | char      | character     | 8-bit       |
 * | wchar_t   | wide char     | 16-bits     |
 * | char16_t  | unicode char  | 16-bits     |
 * | char32_t  | unicode char  | 32-bits     |
 * | short     | short int     | 16-bits     |
 * | int       | integer       | 16-bits     |
 * | long      | long int      | 32-bits     |
 * | longlong  | very long int | 64-bits     |
 * | float     | single-precisi| 32-bits     |
 * | double    | double -||-   | 64-bits     |
 * |long double| -""-          | 10/16-bytes  |
 * -------------------------------------------
*/

