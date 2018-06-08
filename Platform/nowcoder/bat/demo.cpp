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

class Solution {
public:
    vector<vector<bool>> flag; //访问标志
    int movingCount(int threshold, int rows, int cols)
    {
        for (int i = 0; i < rows; i++) {
            vector<bool> vec;
            for (int j = 0; j < cols; j++) {
                vec.push_back(false);
            }
            flag.push_back(vec);
        }

        return movCount(threshold, rows, cols, 0, 0);
    }
    int movCount(int threshold, int rows, int cols, int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= rows || flag[i][j] || !check(threshold, i, j)) {
            return 0;
        }
        cout << i << " " << j << endl;
        flag[i][j] = true;
        return movCount(threshold, rows, cols, i - 1, j) + movCount(threshold, rows, cols, i + 1, j) + movCount(threshold, rows, cols, i, j - 1) + movCount(threshold, rows, cols, i, j + 1) + 1;
    }
    bool check(int threshold, int row, int col)
    {
        int num = 0;
        while (row != 0) {
            num += row % 10;
            row /= 10;
        }
        while (col != 0) {
            num += col % 10;
            col /= 10;
        }
        if (num > threshold) {
            return false;
        }
        return true;
    }

private:
    void echo()
    {
        for (int i = 0; i < flag.size(); i++) {
            for (int j = 0; j < flag[0].size(); j++) {
                cout << flag[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(14, 10, 10) << endl;
    // cout << s.check(10, 27, 11) << endl;
    return 0;
}