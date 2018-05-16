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
    7

    00000000    00000000    0000000     00000111
    00000000    00000000    0000000     00000011
    00000000    00000000    0000000     00000001
    00000000    00000000    0000000     00000000
*/

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while(n != 0){
            count++;
            n = n & (n - 1);
        }
        return count;
    }

    int  NumberOf2(int n) {
        int count = 0;
        for(int i=0 ; i<32 ; i++){
            if(n >> i & 1){
                count++;
            }
        }
        return count;
    }
    int  NumberOf3(int n) {
        int count = 0;
        while(n != 0){
            count += n&1;
            n = n>>1;
        }
        return count;
    }
    
private:

};

int main()
{
    Solution s;
    cout<<s.NumberOf3(7)<<endl;
    return 0;
}
