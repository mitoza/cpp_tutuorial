#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // Print "Hello World"
    cout << "Hello World" << endl;

    // Print all arguments from
    cout << "You have entered " << argc<< " arguments:" << "\n";
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    // Enter the name
    char s[50];
    cout << "Enter your name: ";
    cin.getline(s, 50);
    // cin >> s; // read only one value
    // cin.get(s, 50); // read only once
    //cin.ignore(); // can make read .get() method more then once
    cout << "Your name: " << s;

    return 0;
}
