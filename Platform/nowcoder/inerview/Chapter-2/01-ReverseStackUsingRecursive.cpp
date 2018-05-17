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
#include<deque>
#include<stack>
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
    翻转栈
*/

class Solution {
public:
    
    void reverse(stack<int> &stack) {
        if( stack.empty() ){
            return;
        }
        int i = getAndRemoveLastElement(stack);
        reverse(stack);
        stack.push(i);
    }

    int getAndRemoveLastElement(stack<int> &stack) {
        int result = getAndRemoveFristElement(stack);
        if( stack.empty() ){
            return result;
        }else{
            int last = getAndRemoveLastElement(stack);
            stack.push(result);
            return last;
        }
    }

    int getAndRemoveFristElement(stack<int> &stack){
        if( stack.empty() ){
            return -1;
        }else{
            int result = stack.top();
            stack.pop();
            return result;
        }
    }
private:
};
int main()
{
    Solution s;
    stack<int> s1;
        for(int i=1 ; i<=5 ; i++) s1.push(i);

    // cout<<s.getAndRemoveFristElement(s1)<<endl;
    // cout<<s.getAndRemoveLastElement(s1)<<endl;
    s.reverse(s1);
    while( !s1.empty() ){
        cout<<s.getAndRemoveFristElement(s1)<<" ";
    }
    return 0;
}
