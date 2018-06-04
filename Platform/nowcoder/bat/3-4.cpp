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

class Rotation {
public:
    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
        A = A.append(A);
        int i = 0, j = 0;
        while (i < A.length() - B.length()+1){
            if (A[i+j] == B[j]){
                j++;
                if (j == B.length() - 1)
                    return true;
            }
            else{
                i++;
                j = 0;
            }
        }
        return false;
    }
};


int main()
{
    Rotation s;
    string str1 = "cdba";
    string str2 = "abcd";
    cout<<str1<<endl;
    cout<< s.chkRotation(str1, 4 , str2, 4)<<endl;
    return 0;
}
