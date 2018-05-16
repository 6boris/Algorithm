#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int size = rotateArray.size();
        if(size == 0){
            return 0;
        }
        int left = 0, right = size -1;
        int mid = 0;

        while(rotateArray[left] >= rotateArray[right]){
            //分界点
            if(right - left ==1){
                mid = right;
                break;
            }
            mid = left + (right - left) / 2;
            // rotateArray[left] rotateArray[right] rotateArray[mid]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[left] == rotateArray[right] && rotateArray[left]){
                return MinOrder(rotateArray, left , right);
            }
            // 中间元素位于前面的递增子数组
            // 此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }
            // 中间元素位于后面的递增子数组
            // 此时最小元素位于中间元素的前面
            else{
                right = mid;
            }
        }
        return rotateArray[mid];
    }
private:
    // 顺序寻找最小值 
    int MinOrder(vector<int> &num, int left , int right){
        int result = num[left];
        for(int i=left + 1 ; i<right ; i++){
            if(num[i] < result){
                result = num[i];
            }
        }
        return result;
    }
};


int main()
{
    Solution s;
    // vector<int> num = {0, 1, 2, 3, 4, 5};
    vector<int> num = {4, 5, 6, 7, 1, 2, 3,};
    // vector<int> num = {2, 2, 2, 2, 1, 2};
    
    int result = s.minNumberInRotateArray(num);
    cout<<result<<endl;
    return 0;
}
