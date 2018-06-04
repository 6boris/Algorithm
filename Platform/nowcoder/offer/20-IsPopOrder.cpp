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

/*
入栈1,2,3,4,5
出栈4,5,3,2,1
首先1入辅助栈，此时栈顶1≠4，继续入栈2
此时栈顶2≠4，继续入栈3
此时栈顶3≠4，继续入栈4
此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3
此时栈顶3≠5，继续入栈5
此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3
….
依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的弹出顺序。
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0) {
            return false;
        }
        vector<int> stack;
        for (int i = 0, j = 0; i < pushV.size();) {
            stack.push_back(pushV[i++]);
            while (j < popV.size() && stack.back() == popV[j]) {
                stack.pop_back();
                j++;
            }
            // cout << "pushV: ";
            // echo(pushV);
            // cout << "popV : ";
            // echo(popV);
            // cout << "stack: ";
            // echo(stack);
            // cout << endl;
        }

        return stack.empty();
    }

    bool IsPopOrder1(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0 || popV.size() == 0) {
            return false;
        }
        stack<int> stk;

        int popIndex = 0;
        for (int i = 0; i < pushV.size(); i++) {
            stk.push(pushV[i]);

            while (!stk.empty() && stk.top() == popV[popIndex]) {
                stk.pop();
                ++popIndex;
            }
        }
        return stk.empty();
    }

    void echo(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
};

int main()
{
    Solution s;
    vector<int> num1 = { 1, 2, 3, 4, 5 };
    vector<int> num2 = { 3, 4, 2, 5, 1 };
    cout << s.IsPopOrder1(num1, num2) << endl;

    return 0;
}
