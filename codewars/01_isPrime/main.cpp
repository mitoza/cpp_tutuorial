// main.cpp
#include <iostream>
#include <math.h>

using namespace std;

long long  powmod(long long int base, int exponent, long long int mod);
int GCD(int a, int b);
int EulerPhi(unsigned int n);

// https://en.wikipedia.org/wiki/AKS_primality_test
bool isPrime(int num) {

  if (num <= 1) return false;
  if (num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;
  if (num % 3 == 0) return false;
  if (num > 5 && num % 5 == 0) return false;
  if (num > 7 && num % 7 == 0) return false;

  // 1. If n=a^b for integers a>1 and b>1, out: false;
  for(int b=2; b <=log2(num); b++) {
    double a = pow(num, 1.0f/b);
    //cout << "A[" << b << "]: " << a << endl;
    if (a == (int)a) return false;
  }

  // 2. Find the smallest r such that Or(n) > (ln(n))^2
  float maxk = pow(log2(num),2);
  int maxr = max(3, (int)pow(log2(num), 5));
  bool nextR = true;
  int r=2;
  int k;
  while(nextR && r < maxr) {
    nextR = false;
    k=1;
    while(!nextR && k <= maxk) {
      // https://stackoverflow.com/questions/12253931/using-pow-for-large-number
      nextR = (powmod(num, k, r) == 1) || (powmod(num, k, r) == 0);
      k++;
      cout << "K: " << k << " Pow: " << pow(num, k) << endl;
    }
    r++;
  }
  r--;

  cout << "R: " << r << " EulerPhi: " << EulerPhi(r) << endl;

  // 3. If 1 < gcd(a,n) < n for some a ? r, output composite.
  for(int a=r; a > 1; a--) {
      if (GCD(a, num) != 1) return false;
  };

  // 5.
  int endOfA = sqrt(EulerPhi(r)) * log2(num);
  cout << "EndOfA: " << endOfA << endl;
  for(int a=1; a<endOfA; a++) {

  }
  // http://yves.gallot.pagesperso-orange.fr/src/aks.html
  /*
  P<x> := PolynomialRing(IntegerRing(n));
  for a := 1 to Floor(2*Sqrt(r)*logn) do
      if Modexp(x - a, n, x^r - 1) ne x^(n mod r) - a then
          return false;
      end if;
  end for;
  */
  // https://www.geeksforgeeks.org/aks-primality-test/

  // Also check https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test


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

long long  powmod(long long int base, int exponent, long long int mod) {
  long long int result = 1;
  while (exponent > 0) {
    if (exponent & 1) {
        result = (result * base) % mod;
    }
    exponent = exponent >> 1;
    base = (base * base) % mod;
  }
  return result;
}

int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}

int EulerPhi(unsigned int n) {
  unsigned int result = 1;
  for (int i = 2; i < n; i++) {
    if (GCD(i, n) == 1) {
      result++;
    }
  }
  return result;
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
    cout << "31: " << (isPrime(31) ? "+" : "-") << endl;
    //largeTest();

    cout << "PowMod 2 5 13: " << powmod(2,5, 13) << endl;
    //cout << "GCD(29,31): " << GCD(12,30) << endl;
    //cout << "EulerPhi(36): " << EulerPhi(36) << endl;

    // BestTime: 2.666s

    return 0;
}
