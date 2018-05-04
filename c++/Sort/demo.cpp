#include<iostream>
using namespace std;

void InsertSort(int arr[] , int n){
    for( int i=1 ; i<n ; i++ ){
        for( int j=i ; j>0 && arr[j]<arr[j-1] ; j-- ){
            swap(arr[j] , arr[j-1]);
        }
    }
}


void sort(int arr[] , int n){
    for( int i=1 ; i<n ; i++ ){
        int j , e = arr[i];
        for( j=i ; i>0 && arr[j-1]>e ; j-- ){
            arr[j] = arr[j-1];
        }
        arr[j] = e;                                                                                                                                                                                                                                                              
    }
}

void insert(int arr[] , int n){
    for(int i=1 ; i<n ; i++){
        int j , e = arr[i];
        for( j=i ; j>0 && arr[j]<arr[j-1] ; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

void demo(int arr[] , int n ){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1 &&  arr[j] > arr[j+1]; j++) {
            swap(arr[j] , arr[j+1]);
        }
    }
}

void demo1(int arr[] , int n ){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1 ; j++) {
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

void demo3( int arr[] , int len ){
    for( int i=0 ; i<len-1 ; i++ ){
        for( int j=i ; j<len-i-1 ; j++ ){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[10] = {1,54,2,3,4,9,7,11,2,19};
    // demo1(arr , 10);
    for( int i = 0 ; i < 10 ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    demo3(arr , 10);
    for( int i=0 ; i<10 ; i++ ){
        cout<<arr[i]<<" ";
    }

    return 0;
}