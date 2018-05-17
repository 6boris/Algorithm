#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <malloc.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。*/

class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        vector<int> res;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1) {
                res.push_back(array[i]);
            }
        }
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 0) {
                res.push_back(array[i]);
            }
        }
        array = res;
    }
    void echo(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    bool isEven(int num)
    {
        if (num % 2 == 0) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    s.echo(arr);
    s.reOrderArray(arr);
    s.echo(arr);
    return 0;
}
