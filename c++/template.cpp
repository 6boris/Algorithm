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
#include<iterator>
#include<math.h>
#include<malloc.h>
#include<string.h>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

class Solution{
public:
    void echo(vector<int> arr){
        pt();
        for(int i=0 ; i<arr.size() ; i++){
            cout<<arr[i]<<" ";
        }
    }
private:
    void pt(){
        cout<<"Arr:"<<endl;
    }
};


int main()
{
    Solution s;
    vector<int> num = {0, 1, 2, 3, 4, 5};

    s.echo(num);
    return 0;
}
