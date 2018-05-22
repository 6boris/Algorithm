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

class Solution {
public:
    void push(int value)
    {
        stack1.push(value);
    }
    void pop()
    {
        stack1.pop();
    }
    int top()
    {
        return stack1.top();
    }
    int min()
    {
        int min = 0;
        if (!stack1.empty()) {
            min = stack1.top();
            stack2.push(min);
            stack1.pop();
        }
        while (!stack1.empty()) {
            if (min > stack1.top()) {
                min = stack1.top();
                stack2.push(min);
                stack1.pop();
            } else {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return min;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s;
    stack<int> stk;
    stk.push(3);
    stk.push(5);
    stk.push(2);
    stk.push(8);
    stk.push(7);
    stk.push(9);
    stk.push(4);
    cout << s.min() << endl;
    ;
    return 0;
}
