#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include <cassert>
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

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> array_temp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();

        for (; ib1 != array.end();){            //遇见偶数，就保存到新数组，同时从原数组中删除
            if (*ib1 % 2 == 0) {
                array_temp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }else{
                ib1++;
            }
        }
        
        vector<int>::iterator ib2, ie2;
        ib2 = array_temp.begin();
        ie2 = array_temp.end();

        for (; ib2 != ie2; ib2++){
            array.push_back(*ib2);
        }
    }
    void echo(vector<int> arr){
        for(int i=0 ; i<arr.size() ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
private:
    bool isEven(int num){
        if(num%2 == 0){
            return true;
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s.echo(arr);
    s.reOrderArray(arr);
    s.echo(arr);
    return 0;
}
