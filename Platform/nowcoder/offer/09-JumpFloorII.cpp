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
2   1-2     2
3   1-2-3       2-3     1-3     3
4   1-2-3-4     2-3-4   1-3-4   1-4    1-2-4

当前台阶的跳发总数 = 当前后一阶台阶的跳发总数 + 当前后一阶台阶的跳发总数 
f(0) = 0
f(1) = 1
f(2) = f(2-1) + f(2-2)
f(3) = f(3-1) + f(3-2) + f(3-3)
f(4) = f(4-1) + f(4-2) + f(4-3) + f(4-4)
.......
f(n) = f(n-1) + f(n-2) + ..... + f(n-n)
        =f(0) + f(1) + ... + f(n-1)

f(n-1) = f(0) + f(1) + ... +f((n-1)-1)
        =f(0) + f(1) + ... +f(n-2)

f(n) = 2 * f(n-1)  n>=2
f(2) = 2
f(1) = 1
f(0) = 0 
*/

class Solution{
public:
    // 非递归
    int jumpFloorII(int number) {
        int jumpFlo=1;
        while(--number){
            jumpFlo *= 2;
        }
        return jumpFlo;
    }
    // 递归
    int jumpFloorIII(int number){
        if(number <= 0){
            return 0;
        }else if( number ==1 ){
            return 1;
        }else{
            return 2 * jumpFloorIII(--number);
        }
    }
 
private:

};

int main()
{
    Solution s;
    cout<<"1: "<<s.jumpFloorII(1)<<endl;
    cout<<"2: "<<s.jumpFloorII(2)<<endl;
    cout<<"3: "<<s.jumpFloorII(3)<<endl;
    cout<<"4: "<<s.jumpFloorII(4)<<endl;
    cout<<"5: "<<s.jumpFloorII(5)<<endl;
    cout<<"5: "<<s.jumpFloorIII(5)<<endl;
    return 0;
}
