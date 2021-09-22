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
};

int main(int argc, char** argv) {

    cout << "C++ Data Types" << endl;

    // Primitive integer variables
    int i = 1; // Size 2 bytes or 4 bytes
    char c = 65; // Size 1 byte
    long int l;

    // Boolean
    bool b; // Size: unidentify

    // Primitive floating point
    float f = 3.1425f; // Size 4 bytes
    double d = 3.1425; // Size 8 bytes

    // User defined types
    Day day = MON; // enum
    MyDay myday = day; // typedef
    string s; // class string

    // Derived Array variables

    // Derived Pointer variables

    // Derived Reference variables

    return 0;
}
