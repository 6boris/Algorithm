#include <iostream>
using namespace std;

    int *selectionSort(int *A, int n) {
        int tmp  = 0;
        for(int i=0; i<n ; i++){
            tmp = i;
            for(int j=i+1 ; j<n ; j++){
                if (A[j] < A[tmp]) {
                    tmp = j;
                }
            }
            if (tmp != i) {
                swap(A[i] , A[tmp]);
            }
        }
        return A;
    }

int main() {
  int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
  selectionSort(arr, 10);

  for (int i = 0; i < 10; i++) {
      cout<<arr[i]<<" ";
  }
  return 0;
}