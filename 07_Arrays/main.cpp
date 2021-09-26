// main.cpp
#include <iostream>

using namespace std;

int maxValue(int A[], int count) {
  int maxValue = A[0];
  for(int i=1; i<count; i++) {
    if (A[i] > maxValue) maxValue = A[i];
  }
  return maxValue;
}

int linearSearch(int search, int A[], int count) {
  for(int i=0; i<count; i++) {
    if (search == A[i]) return i;
  }
  return 0;
}

int binarySearch(int search, int B[], int count) {
  int low=0, high = count-1;
  int middle;
  while(low<=high) {
    middle = (low+high)/2;
    if (B[middle]==search) {
      return low;
    } else if (search < B[middle]) high = middle - 1;
    else low = middle + 1;
  }
  return -1;
}

void drawUpperTriangle(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j)
        cout << "*" << " ";
      else
        cout << " " << " ";
    }
    cout << endl;
  }
}

int main(int argc, char** argv) {

  cout << "C++ Arrays" << endl;

  // Initialization types
  int A[10] = {6,11,25,8,15,7,12,20,9,14};
  int C[20] = {0};
  float D[] = {1.1f,2.3f,3.2f,4};
  char E[] = {65, 'B', 67, 'D'};

  // How work with arrays from for
  for(int i=0; i<10; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  // For each
  for(auto x: D) { // You can use reference to change the value: for(auto& x: D) {}
    cout << x << " ";
  }
  cout << endl;

  // Max value of array
  cout << "Max value of A array: " << maxValue(A, 10) << endl;

  // Linear search
  cout << "Linear search. Index of 12 is: " << linearSearch(12, A, 10) << endl;

  // Binary Search
  int B[] = {6,2,13,17,20,22,25,28,30,35}; // Sorted in order array
  cout << "Binary search. Index of 17 is: " << binarySearch(17, B, 10) << endl;

  // Nested loops
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      cout << "(" << i << "," << j << ") ";
    }
    cout << endl;
  }

  // Patterns
  cout << "Draw Upper Triangle" << endl;
  drawUpperTriangle(5);

  // Multidimensional Arrays
  int A2[2][3] = {{1,2,3}, {4,5,6}}; // Rows: 2, Columns: 3
  int B2[2][3] = {1,2,3,4,5,6};
  int C2[2][3] = {1,2};
  for(int i=0; i<2; i++) {
    for(int j=0; j<3; j++) {
      cout << "(" << C2[i][j] << ") ";
    }
    cout << endl;
  }

  // 2D Arrays with For Each Loop
  for(auto& x:B2) {
   for(auto& y:x) {
     cout << y << " ";
   }
    cout << endl;
  }

  // SizeOf array
  cout << "Size of Array: " << sizeof(A) << " bytes" << endl;

  return 0;
}
