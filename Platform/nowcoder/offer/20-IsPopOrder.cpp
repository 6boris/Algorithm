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
        int len = pushV.size();
        if (len == 0 || len != popV.size()) {
            return false;
        }
        int i, j;
    }

private:
};

int main()
{
    Solution s;
    vector<int> num1 = { 0, 1, 2, 3, 4, 5 };
    vector<int> num2 = { 5, 4, 3, 2, 1, 0 };

    s.IsPopOrder(num1, num2);
    return 0;
}
