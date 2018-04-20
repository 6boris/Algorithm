#include<iostream>
using namespace std;

void SelectSort(int arr[] , int len){
    int temp=0 , k=0;
    for(int i=0 ; i<len-1 ; i++ ){
        k=i;
        for(int j=i+1 ; j<len ; j++ ){
            if(arr[k] > arr[j]){
                k = j;
            }
        }
        if(k != i){
            temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
        }
    }
}


int main(){
    int arr[10] = {1,2,3,4,5,22,3,7,1,2};

    for(int i=0 ; i<10 ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    SelectSort(arr , 10);
    // select_sort(arr , 10);
    for(int j=0 ; j<10 ; j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    return 0;
}