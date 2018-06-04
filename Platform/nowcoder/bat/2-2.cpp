#include <iostream>
using namespace std;

int* bubbleSort(int* A, int n) {
    int tmp = 0;
    for (int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n-i-1 ; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j] , A[j+1]);
            }
        }
    }
    return A;
}

int main() {
  int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
  bubbleSort(arr, 10);

  for (int i = 0; i < 10; i++) {
      cout<<arr[i]<<" ";
  }
  return 0;
}