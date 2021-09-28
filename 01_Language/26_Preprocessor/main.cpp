// main.cpp
#include <iostream>

using namespace std;

//#define PI 3.1425
#define c cout
#define SQR(x)(x*x)
#define MSG(x) #x // will convert x to "x"

#ifndef PI
  #define PI 3.1425 //  - symbol constant
#endif

int main(int argc, char** argv) {

    cout << "C++ Preprocessor" << endl;

    c << "PI:" << PI << endl; // compiler will change PI to 3.1425
    c << "SQR:" << SQR(5) << endl; // compiler will change SQR(5) to 5*5
    c << MSG(Hello Message) << endl;

    return 0;
}
