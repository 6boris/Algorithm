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
    // 访问标志
    vector< vector<int> > flag;

    // int bfs(int threshold, int rows , int cols, int i , int j){
    //     if(i<0 || i>=rows || j<0 || j >=cols || flag[i][j]){
    //         return 0;
    //     }
    //     flag[i][j] = true;
    //     cout<<
    //     return bsf(threshold, rows, cols, i-1, j) + 
    //         bsf(threshold, rows, cols, i+1, j) + 
    //         bsf(threshold, rows, cols, i, j-1) + 
    //         bsf(threshold, rows, cols, i, j+1) + ;
    // }

    int movingCount(int threshold, int rows, int cols)
    {
        movCount(threshold, rows, cols, 0, 0);
        return 0 ;
    }

    int movCount(int threshold, int rows, int cols,int i,int j)//访问的是当前的单元
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || (threshold, i, j) || flag[i][j]) return 0;
        cout<<"i: "<<i<<" j: "<<j<<endl;
        flag[i][j] = true;
        return movCount(threshold, rows, cols, i - 1, j) +
            movCount(threshold, rows, cols, i + 1, j) +
            movCount(threshold, rows, cols, i , j-1) +
            movCount(threshold, rows, cols, i , j+1) +1;

    }

    bool check(int threshold, int row, int col){
        int num = 0 ;
        while(row != 0){
            num += row % 10;
            row /= 10;
        }
        while(col != 0){
            num += col % 10;
            col /= 10;
        }
        if( num <= threshold){ 
            return true;
        }
        return false;
    }

private:

};


int main()
{
    Solution s;

    cout<<s.movingCount(10, 5, 5)<<endl;
    return 0;
}
