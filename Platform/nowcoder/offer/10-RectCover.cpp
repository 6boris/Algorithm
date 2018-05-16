#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<sstream>
#include<iterator>
#include<math.h>
#include<malloc.h>
#include<string.h>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*
    Address:    https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6
    Title:      矩形覆盖
    Description: 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的
                小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 
    f(0) = 0
    f(1) = 1
    f(2) = 2
    f(n) = f(n-1) + f(n-2)

*/

class Solution {
public:
    int rectCover(int number) { 
        if (number < 1) {
            return 0;
        } else if (number == 1 || number == 2) {
            return number;
        } else {
            return rectCover(number-1) + rectCover(number-2);
        }
    }

    int rectCover2(int number){
        if(number <= 2){
            return number;
        }
        return rectCover2(number -1) + rectCover2(number -2);
    }

private:

};


int main()
{
    Solution s;

    cout<<s.rectCover2(4)<<endl;
    return 0;
}
