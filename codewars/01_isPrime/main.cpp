// main.cpp
#include <iostream>
#include <string>
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

bool IsPrime(int n){
	if (n < 2) return false;
	if (n < 4) return true;
	if (n % 2 == 0) return false;

	const int iMax = (int)sqrt(n) + 1;
	int i;
	for (i = 3; i <= iMax; i += 2)
		if (n % i == 0)
			return false;

	return true;
}


// Miller Robin Prime Test  https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
int power(int x, unsigned int y, int p){
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

bool miillerTest(int d, int n){
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    // Return composite
    return false;
}

bool isPrimeMiller(int num){
    int k = 5;
    if (num <= 1 || num == 4)  return false;
    if (num <= 3) return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = num - 1;
    while (d % 2 == 0)
        d /= 2;
    cout << "D: " << d << " N: " << num << endl;
    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
         if (!miillerTest(d, num))
              return false;

    return true;
}

/* // My PrimeTest
bool isPrime(int num) {
  if (num <= 1) return false;
  if (num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;
  if (num % 3 == 0) return false;
  if (num > 5 && num % 5 == 0) return false;
  if (num > 7 && num % 7 == 0) return false;
  int i=sqrt(num);
  while (i < num/2) {
    if (num % i == 0) return false;
    i++;
  }
  return true;
}
*/

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

    //cout << "PowMod 2 5 13: " << powmod(2,5, 13) << endl;
    //cout << "GCD(29,31): " << GCD(12,30) << endl;
    //cout << "EulerPhi(36): " << EulerPhi(36) << endl;

    // BestTime: 2.666s

    return 0;
}
