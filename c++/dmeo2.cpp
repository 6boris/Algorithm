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

using namespace std;

string reverse(string str)
{
    stack<char> stk;
    int index = 0;
    while (index < str.length()) {
        stk.push(str[index]);
        index++;
    }
    string s2;

    while (!stk.empty()) {
        s2 += stk.top();
        stk.pop();
    }
    return s2;
}

int main(int argc, char const* argv[])
{
    string s1;
    // cin >> s1;
    // stack<string> stack;
    // reverse(s1.begin(), s1.end());
    // cout << s1.length() << endl;

    // string s2 = "asdasd";
    // s2 = reverse(s2);
    // cout << s2 << endl;
    int arr[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
    int nowSum = 0;
    int maxSum = 0;
    for (int i = 0; i < 8; i++) {
        cout << "now:" << arr[i] << " nowSum: " << nowSum << " maxSum:" << maxSum << endl;
        if (nowSum <= 0) {
            nowSum = arr[i];
        } else {
            nowSum += arr[i];
        }
        if (nowSum > maxSum) {
            maxSum = nowSum;
        }
    }
    cout << nowSum << endl;
    cout << maxSum << endl;
    return 0;
}
