#include <iostream>
using namespace std;

class MergeSort {
public:
    int* mergeSort(int* A, int n)
    {
        //process(A, 0, n-1);//递归实现
        //非递归实现
        for (int step = 2; step / 2 <= n; step *= 2) {
            for (int i = 0; i < n; i += step) {
                int mid = i + step / 2 - 1;
                if (mid + 1 < n) {
                    merge(A, i, mid, mid + 1, min(i + step - 1, n - 1));
                }
            }
        }
        return A;
    }
    // 递归precess
    void process(int* A, int left, int right)
    {
        if (left < right) {
            int mid = (left + right) / 2;
            process(A, left, mid);
            process(A, mid + 1, right);
            merge(A, left, mid, mid + 1, right);
        }
    }

    void merge(int* A, int L1, int R1, int L2, int R2)
    {
        int i = L1, j = L2;
        int temp[100], index = 0;
        while (i <= R1 && j <= R2) {
            if (A[i] <= A[j]) {
                temp[index++] = A[i++];
            } else {
                temp[index++] = A[j++];
            }
        }
        while (i <= R1)
            temp[index++] = A[i++];
        while (j <= R2)
            temp[index++] = A[j++];
        for (i = 0; i < index; i++) {
            A[L1 + i] = temp[i];
        }
    }
};

int main()
{
    MergeSort m;
    int arr[] = { 4, 3, 4, 3, 9, 5, 4, 3, 2, 1 };
    m.mergeSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}