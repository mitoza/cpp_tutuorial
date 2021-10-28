// main.cpp
#include <iostream>
#include <math.h>

using namespace std;

// https://en.wikipedia.org/wiki/AKS_primality_test#Example_1:_n_.3D_31_is_Prime
bool isPrime(int num) {

  if (num <= 1) return false;
  if (num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;
  if (num % 3 == 0) return false;
  if (num > 5 && num % 5 == 0) return false;
  if (num > 7 && num % 7 == 0) return false;

  // If n=a^b for integers a>1 and b>1, out: false;
  double a;
  for(int b=2; b <=log(num); b++) {
    a = pow(num, 1.0f/b);
    //cout << "A[" << b << "]: " << a << endl;
    if (a == (int)a) return false;
  }

  // Find the smallest r such that Or(n) > (ln(n))^2
  float maxk = pow(log(num),2);
  int maxr = max(3, (int)pow(log(num), 5));
  bool nextR = true;
  int r=2;
  int k;
  while(nextR && r < maxr) {
    nextR = false;
    k=1;
    while(!nextR && k <= maxk) {
        // https://stackoverflow.com/questions/12253931/using-pow-for-large-number - mod?
      nextR = (((int)(pow(num, k)) % r == 1) || (((int)pow(num, k)) % r == 0));
      k++;
      cout << "K: " << k << " Pow: " << pow(num, k) << endl;
    }
    r++;
  }

  cout << "R: " << r << endl;



  // Old Method
  /*
  int i=sqrt(num);
  while (i < num/2) {
    if (num % i == 0) return false;
    i=i+1;
  }
*/
  return true;
}

int mod(long n, int modul) {
  long res = 1;
  for(long i=0; i < n; ++i) {
    res *= 2;
    if(res > modul) res %= modul;
  }
  return res;
}

void mainTest() {
    cout << "0: " << (isPrime(0) ? "-" : "+") << endl;
    cout << "1: " << (isPrime(1) ? "-" : "+") << endl;
    cout << "2: " << (isPrime(2) ? "+" : "-") << endl;
    cout << "4: " << (isPrime(4) ? "-" : "+") << endl;
    cout << "6: " << (isPrime(6) ? "-" : "+") << endl;
    cout << "8: " << (isPrime(8) ? "-" : "+") << endl;
    cout << "9: " << (isPrime(9) ? "-" : "+") << endl;
    cout << "45: " << (isPrime(45) ? "-" : "+") << endl;
    cout << "73: " << (isPrime(73) ? "+" : "-") << endl;
    cout << "75: " << (isPrime(75) ? "-" : "+") << endl;
    cout << "-1: " << (isPrime(-1) ? "-" : "+") << endl;

    cout << "3: " << (isPrime(3) ? "+" : "-") << endl;
    cout << "5: " << (isPrime(5) ? "+" : "-") << endl;
    cout << "7: " << (isPrime(7) ? "+" : "-") << endl;
    cout << "41: " << (isPrime(41) ? "+" : "-") << endl;
}

void largeTest() {
    cout << "247464361: " << (isPrime(247464361) ? "-" : "+") << endl;
    cout << "1634300119: " << (isPrime(1634300119) ? "+" : "-") << endl;

    //cout << "1634300136: " << (isPrime(1634300136) ? "-" : "+") << endl;
    //cout << "1634300099: " << (isPrime(1634300099) ? "+" : "-") << endl;
}

int main(int argc, char** argv) {

    //mainTest();
    //cout << "5099: " << (isPrime(5099) ? "+" : "-") << endl;
    //cout << "31: " << (isPrime(31) ? "+" : "-") << endl;
    //largeTest();

    cout << "Mod 16: " << mod(16,15) << endl;

    // BestTime: 2.666s

    return 0;
}
