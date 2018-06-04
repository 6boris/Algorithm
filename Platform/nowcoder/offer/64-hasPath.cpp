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
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        // 遍历的标志
    	vector<bool> used(strlen(matrix), false);
        // bool* flags = new bool[rows*cols];
        for(int i=0;i<rows;i++){
        	for(int j=0;j<cols;j++){
                if(isPath(matrix, rows,cols,i, j,str,0,used))
                    return true;
            }
        }
        return false;
    }
private:
    bool isPath(char* matrix,int rs,int cs ,int row, int col, char* str,int len,vector<bool> used)
    {
        if(len == strlen(str))
            return true;
        int idx  = col+row*cs;
        if(row<0 || row>=rs || col<0 || col>=cs || used[idx] == true || matrix[idx] != str[len])
            return false;
        used[idx] = 1;
        int res =  isPath( matrix,rs,cs ,row-1, col,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row, col-1,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row+1, col,str,len+1,used) ||  
                    isPath( matrix,rs,cs ,row, col+1,str,len+1,used);  
        if(res==true)
            return true;
        used[idx] = 0;
        return false;
    }
};


int main()
{
    /*
        a b c e s 
        f c s a d
        e e

        b c e d 

    */

    Solution s;
    char str1[100] = "abcesfcsadee";
    char str2[100] = "bces";
    // cout<<str1[1]<<endl;
    // s.hasPath(str1, 5, 5, str2);
    cout<<s.hasPath(str1, 5, 5, str2)<<endl;

    return 0;
}
