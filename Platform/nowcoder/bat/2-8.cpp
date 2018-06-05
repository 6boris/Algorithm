#include <iostream>
using namespace std;
class ShellSort {
public:
    int* shellSort(int* A, int n)
    {
        if (A == NULL || n < 2) {
            return nullptr;
        }
        for (int inc = n / 2; inc > 0; inc = inc / 2) {
            int index = 0;
            for (int i = inc; i < n; i++) {
                index = i;
                while (index > 0) {
                    if ((A[index] < A[index - inc]) && (index - inc >= 0)) {
                        swap(A[index], A[index - inc]);
                        index = index - inc;
                    } else {
                        break;
                    }
                }
            }
        }
        return A;
    }
};

int main()
{
    ShellSort s;
    int arr[] = { 4, 3, 4, 3, 9, 5, 4, 3, 2, 1 };
    s.shellSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}