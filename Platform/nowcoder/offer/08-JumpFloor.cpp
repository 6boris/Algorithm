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
1   1
2   1-2
3   1-2-3       2-3     1-3
4   1-2-3-4     2-3-4   1-3-4   1-4    1-2-4
5   

当前台阶的跳发总数 = 当前后一阶台阶的跳发总数 + 当前后一阶台阶的跳发总数 
f(n) = f(n-1) + f(n-2)
*/


class Solution{
public:
    int jumpFloor(int num){
        if(num <=2 ){
            return num;
        }
        int frist = 1 , second = 2 , thrid = 0; 
        for(int i=3 ; i<=num ; i++){
            thrid = frist + second;
            frist = second;
            second = thrid;
        }
        return thrid;
    }
private:

};

int main()
{
    Solution s;
    cout<<"1: "<<s.jumpFloor(1)<<endl;
    cout<<"2: "<<s.jumpFloor(2)<<endl;
    cout<<"3: "<<s.jumpFloor(3)<<endl;
    cout<<"4: "<<s.jumpFloor(4)<<endl;
    cout<<"5: "<<s.jumpFloor(5)<<endl;
    return 0;
}
