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
    bool isValid(string str){
        if (str == "") {
            return false;
        }
        int status = 0;
        for (int i=0 ; i<str.length() ; i++) {
            if (str[i] != ')' && str[i] != '('){
                return false;
            }
            if (str[i] == ')' && --status < 0) {
                return false;
            }
            if (str[i] == '('){
                status++;
            }
        }
        return status == 0;
    }
private:

};


int main()
{
    Solution s;
    string str1 = "(())(())";
    string str2 = "(())(()(()))";
    string str3 = "(())(()(())";
    
    cout<<str1<<" "<<s.isValid(str1)<<endl;
    cout<<str2<<" "<<s.isValid(str2)<<endl;
    cout<<str3<<" "<<s.isValid(str3)<<endl;
    return 0;
}
