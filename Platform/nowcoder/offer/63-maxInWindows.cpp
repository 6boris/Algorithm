#include<algorithm>
#include<cmath>
#include<deque>
#include<iostream>
#include<set>
#include<string>
#include<sstream>
#include<stack>
#include<string.h>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<iterator>
#include<math.h>
#include<malloc.h>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        // 处理极端情况
        if (num.size()<=0 || size>num.size() || size<=0) {
            return res;
        }
        // 滑动窗口数量
        int n = num.size() + 1 - size;

        for (int i=0 ; i<n ; i++) {
            vector<int> tmp;
            int max = num[i];
            for (int j=i ; j<i+size ; j++) {
                tmp.push_back(num[j]);
                if(num[j] > max){
                    max = num[j];
                }
            }
            res.push_back(max);
        }
        return res;
    }
};


int main()
{
    Solution s;
    vector<int> num1 = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> num2;
    num2 = s.maxInWindows(num1 , 3);
    cout<<"Res: ";
    for (int i=0 ; i<num2.size() ; i++) {
        cout<<num2[i]<<" ";
    }
    return 0;
}
