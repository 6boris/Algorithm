#include<iostream>
#include<ctime>

using namespace std;

/**
 * @随机生成测试数据 
 * 
 * @param arr 
 * @param n 
 * @param rangeL 
 * @param rangeR 
 */
void Random(int arr[] , int n ,int rangeL , int rangeR){
    for( int i = 0 ; i < n ; i++ ){
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
}


int main(){
    int a[10];
    Random( a , 10 , 20 , 40);
    for( int i = 0 ; i < 10 ; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}