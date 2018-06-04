#include <iostream>
using namespace std;

    int* insertionSort(int* A, int n) {
        for (int i=0 ; i<n ; i++) {
            int tmp = A[i];
            int j = i - 1;
            while (j >= 0 && tmp < A[j]) {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = tmp;
        }
        return A;
    }

int main() {
  int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
  insertionSort(arr, 10);

  for (int i = 0; i < 10; i++) {
      cout<<arr[i]<<" ";
  }
  return 0;
}