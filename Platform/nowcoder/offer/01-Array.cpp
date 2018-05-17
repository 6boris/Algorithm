#include <iostream>

using namespace std;

void echo(int arr[5][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}

bool judge(int arr[5][5], int num)
{
    for (int i = 0; i < 5;) {
        for (int j = 5 - 1; j >= 0;) {
            cout << arr[i][j] << endl;
            if (arr[i][j] > num) {
                j--;
                continue;
            } else if (arr[i][j] < num) {
                i++;
                continue;
            } else {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int arr[5][5] = {
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 },
        { 26, 27, 28, 29, 30 },
        { 31, 32, 33, 34, 35 },
    };
    // echo(arr);
    cout << judge(arr, 26) << endl;
    return 0;
}
