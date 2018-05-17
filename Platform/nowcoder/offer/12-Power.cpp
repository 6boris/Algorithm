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
    1、base为0，exponent<0，无效的输入，2、指数为正，3、指数为负,4、指数为0
    1.base = 0 
    2.exponent = 0
    3.exponent > 0
    4.exponent < 0

    位移计算
    10^13 =  10^1101 = 10^0001 + 10^0100 + 10^1000
    通过 &1 和 >>1 来逐步读取 1101

*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)       return 0;
        if(exponent == 0)   return 1;
        if(exponent == 1)   return base;
        if(exponent == -1)  return 1 / base;

        int n = 0;
        double num = 1;
        if(exponent < 0)    n = -exponent;
        while(n != 0){
            if( (exponent&1) ==0 ){
                num *= base;
            }
            base *= base;
            n >>= 1;
        }
        return exponent>0 ? num : (1/num);

    }
    double Power1(double base, int exponent) {
        if(base == 0)       return 0;
        if(exponent == 0)   return 1;
        if(exponent == 1)   return base;
        if(exponent == -1)  return 1 / base;
        if(exponent > 0){
            double num = base;
            while(exponent > 1){
                num = num * base;
                exponent--;
            }
            return num;
        }else{
            double num = base;
            exponent = -exponent;
            while(exponent > 1){
                num = num * base;
                exponent--;
            }
            return 1 / num;
        }
    }

private:

};

int main()
{
    Solution s;
    cout<<"s:"<<s.Power(5,7)<<endl;
    return 0;
}
