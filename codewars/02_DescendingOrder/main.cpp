// main.cpp
#include <iostream>
#include <cinttypes>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

uint64_t descendingOrder(uint64_t a) {
  int len = 0, r;
  uint64_t m = a;
  // Check length
  while(m > 0) {
    m /=10;
    len++;
  }

  int nums[len];
  // Set an array
  m = a;
  for(int i=0; i<len; i++) {
    r = m % 10;
    m /=10;
    nums[i] = r;
  }

  // Bubble sort array
  int maxJ;
  int tmp;
  for(int i=0; i<len-1; i++) {
    maxJ = i;
    for(int j=i+1; j<len; j++) {
      if (nums[maxJ] < nums[j]) maxJ = j;
    }
    if (maxJ == i) continue;
    tmp = nums[i];
    nums[i] = nums[maxJ];
    nums[maxJ] = tmp;
  }

  // Make number
  uint64_t maxNum = 0;
  for(int i=len; i>0; i--) {
    maxNum = maxNum * 10 + nums[len-i];
  }

  return maxNum;
}

int main(int argc, char** argv) {

   cout << "1021: " << descendingOrder(1021) << endl; // 2110


  return 0;
}
