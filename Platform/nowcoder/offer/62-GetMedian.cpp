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
/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/
class Solution {
    vector<int> arr;
public:
    void Insert(int num)
    {
        arr.push_back(num);
    }
    double GetMedian()
    { 
        echo();
        sort(arr.begin() , arr.end());
        cout<<endl;
        echo();
        cout<<endl;
        if(arr.size() % 2 ==1){
            return arr[ (arr.size()-1) / 2 ];
        } else {
            return  ( arr[arr.size() / 2 ] +  arr[arr.size() / 2 - 1] ) / 2.0 ;
        }
    }
private:
    void echo(){
        for (int i=0 ; i<arr.size() ; i++) {
            cout<<arr[i]<<" ";
        }
    }

};


int main()
{
    Solution s;

    s.Insert(5);
    s.Insert(5);
    s.Insert(4);
    s.Insert(7);
    s.Insert(2);
    s.Insert(6);
    s.Insert(1);
    s.Insert(9);
    cout<<s.GetMedian()<<endl;
    return 0;
}
