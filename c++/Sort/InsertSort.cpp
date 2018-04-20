#include<iostream>
using namespace std;

void InsertSort(int arr[] , int len){
    for( int j=0 ; j<len ; j++ ){
        int key = arr[j];//等待排序的第一个元素
        int i = j - 1; //代表已经排完序的元素的最后一个元素
        while( i>=0 && key<arr[i] ){
            // 从后向前比较已经排过序的数组乳沟比他小，则用后者代替前者。
            // 其实就是整个数组向后移动一位，以便找到合适的位置时便于插入
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key; //找到合适的位置了，在I索引的后面设置KEY值
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,22,3,7,1,2};
    for( int i=0 ; i<10 ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    InsertSort( arr , 10 );
    for( int i=0 ; i<10 ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}