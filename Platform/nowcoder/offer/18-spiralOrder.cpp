#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <malloc.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        if (matrix.empty()) {
            return vector<int>();
        }

        vector<int> res;

        // 矩阵行数
        int row = matrix.size() - 1;
        // 矩阵列数
        int column = matrix[0].size() - 1;
        for (int x = 0, y = 0; x <= row && y <= column; x++, y++) {

            // 输出矩阵首行
            for (int j = y; j <= column; j++) {
                res.push_back(matrix[x][j]);
            }
            // 输出居中最右列
            for (int i = x + 1; i <= row; i++) {
                res.push_back(matrix[i][column]);
            }
            // 输出最低行
            for (int j = column - 1; j >= y && x != row; j--) {
                cout << "3" << endl;

                res.push_back(matrix[row][j]);
            }
            // 输出最左列
            for (int i = row - 1; i > x && y != column; i--) {
                cout << "4" << endl;
                res.push_back(matrix[i][y]);
            }
            row--;
            column--;
        }
        return res;
    }

    void echo(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
    }

private:
};

int main()
{
    Solution s;
    vector<vector<int>> num = {
        { 11, 12, 13, 14 },
        { 15, 16, 17, 18 },
        { 19, 20, 21, 22 },
        { 23, 24, 25, 26 }
    };
    vector<vector<int>> num1 = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };

    s.echo(s.printMatrix(num));
    return 0;
}
