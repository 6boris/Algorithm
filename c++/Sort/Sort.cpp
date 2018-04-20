#include<iostream>
#include"BubbleSort.h"

using namespace std;
int main(){
    int len=10 , i=0;
    int arr[10] = {1,4,5,6,7,3,2,3,5,2};
    for( i=0 ; i<len ; i++ ){
        cout<<arr[i]<<" ";
    }
    BubbleSort(arr , len);
    cout<<endl;
    for( i=0 ; i<len ; i++ ){
        cout<<arr[i]<<" ";
    }
    return 0;
}


