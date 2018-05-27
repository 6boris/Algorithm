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
        }
        return stack.empty();
    }

private:
};

int main()
{
    Solution s;
    vector<int> num1 = { 0, 1, 2, 3, 4, 5 };
    vector<int> num2 = { 5, 4, 3, 2, 1, 0 };
    cout << s.IsPopOrder(num1, num2) << endl;
    return 0;
}
