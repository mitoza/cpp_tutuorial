// main.cpp
#include <iostream>

using namespace std;

int naturalSum(int n) {
    int sum=0;
    for(int i=1; i<=10; i++) {
        sum+=i;
    }
    return sum;
}

int factorialOfN(int n) {
    int fact=1;
    for(int i=1; i<=n; i++) {
        fact*=i;
    }
    return fact;
}

void factorsOfN(int n) {
    for(int i=1; i<=n; i++) {
        if(n%i==0) cout << i << " ";
    }
}

void perfectNumber(int n) {
    int sum=0;
    for(int i=1; i<=n; i++) {
        if(n%i==0) {
            sum+=i;
        }
    }
    if(sum==2*n) cout << "perfect";
    else cout << "not perfect";
}

void primeNumber(int n) {
    int count=0;
    for(int i=1; i<=n; i++) {
        if(n%i==0) count++;
    }

    if(count==2) cout << "prime";
    else cout << "not prime";
}

void digitsOfNumber(int n) {
    while (n > 0) {
        cout << (n % 10) << " ";
        n /= 10;
    }
}

void armstrongNumber(int n) {
    int sum = 0, r;
    int m = n;
    while (m>0) {
        r = m % 10;
        m /= 10;
        sum += r * r * r;
    }
    if(sum==n) cout << "armstrong";
    else cout << "not armstrong";
}

int reverseNumber(int n) {
    int rev=0;
    int m=n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

void palindromeNumber(int n) {
    int rev=0;
    int r;
    int m=n;
    while (n > 0) {
        r = n % 10;
        n = n / 10;
        rev = rev*10+r;
    }
    if (rev==m) cout << "palindrome";
    else cout << "not a palindrome";
}

int findGDC(int a, int b) {
    while(a!=b) {
        if (a>b) a-=b;
        else b-=a;
    }
    return a;
}

int main(int argc, char** argv) {

    cout << "C++ Loops" << endl;

    // While implementation
    int i = 0;
    while (1) {
        if (i==5) break;
        cout << i << " ";
        i++;
    }
    cout << endl;

    // Do While implementation
    do {
        cout << i << " ";
        i++;
    } while (i<10);
    cout << endl;

    // For implementation
    for(int j=0; j<10; j++) {
        cout << j << " ";
    }
    cout << endl;

    // For Each implementation
    for(;;) {
        if (i==15) break;
        cout << i << " ";
        i++;
    }
    cout << endl;

    // Sum of first N natural number
    cout << "Sum of 10 natural numbers: " << naturalSum(10) << endl;

    // Find factorial of number
    cout << "Factorial of number 4: " << factorialOfN(4) << endl;

    // Find factors of N
    cout << "Factors of 15: ";
    factorsOfN(15);
    cout << endl;

    // Perfect Number 1+2+3 = 6
    cout << "Number 6 is: ";
    perfectNumber(6);
    cout << endl;

    // Prime Number
    cout << "Number 7 is: ";
    primeNumber(7);
    cout << endl;

    // Digits of number
    cout << "Number 1724 is: ";
    digitsOfNumber(1724);
    cout << endl;

    // Armstrong Number 3^3 + 5^3 + 1^3 = 153
    cout << "Number 153 is: ";
    armstrongNumber(153);
    cout << endl;

    // Reverse number
    cout << "Reverse number of 1934: " << reverseNumber(1934) << endl;

    // Palindrome Number
    cout << "Number 1551 is: ";
    palindromeNumber(1551);
    cout << endl;

    // Find GDC of two numbers
    cout << "GDC of numbers 156 and 972 is " << findGDC(156, 872) << endl;


    return 0;
}
