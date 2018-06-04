#include <iostream>

using namespace std;

int* selectionSort(int* A, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[tmp]) {
                tmp = j;
            }
        }
        if (tmp != i) {
            swap(A[i], A[tmp]);
        }
    }
    return A;
}

int* insertionSort(int* A, int n)
{
    for (int i = 0; i < n; i++) {
        int tmp = A[i];
        int j = i - 1;
        while (j >= 0 && tmp < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
    }
    return A;
}

int main()
{
    int arr[] = { 4, 3, 4, 3, 9, 5, 4, 3, 2, 1 };
    insertionSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}