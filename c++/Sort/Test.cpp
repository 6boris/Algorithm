#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <malloc.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f
#define ARRLENGTH 20

using namespace std;

class Solution {
public:
    void InsertSort(int arr[], int length)
    {
        for (int i = 1; i < length; i++) {
            int e = arr[i], j;
            for (j = i; j > 0 && arr[j - 1] > e; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    void echo(int arr[], int length)
    {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void generateRondomArray(int arr[], int start, int end, int number)
    {
        for (int i = 0; i < number; i++) {
            arr[i] = (rand() % (start - end + 1) + start);
        }
    }

private:
};

int main()
{
    Solution s;
    int arr[ARRLENGTH];
    s.generateRondomArray(arr, 1, 100, ARRLENGTH);
    s.echo(arr, ARRLENGTH);
    s.InsertSort(arr, ARRLENGTH);
    s.echo(arr, ARRLENGTH);
    return 0;
}
