#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <string.h>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <iterator>
#include <math.h>
#include <malloc.h>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

class Checker {
public:
    // bool checkDuplicate(vector<int> a, int n) {
    //     return set<int>(a.begin(), a.end()).size() != n;
    // }
    bool checkDuplicate(vector<int> a, int n) {
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 2; i++) {
            if (a[i] == a[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Checker c;
    // int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
    vector<int> arr = { 4, 3, 4, 3, 9, 5, 4, 3, 2, 1 };
    cout << c.checkDuplicate(arr, 10) << endl;

    return 0;
}