#include<iostream>
using namespace std;

void SelectSort(int arr[], int n){
    for(int i= 0 ; i < n ; i++){
        int minIndex = i;
        for(int j = i ; j < n ; j++){
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

void Random(int arr[] , int n ,int rangeL , int rangeR){
    for( int i = 0 ; i < n ; i++ ){
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
}

int main(){
    int a[50];
    Random(a , 50 , 0 , 1000 );
    SelectSort(a , 50);
    for( int i = 0 ; i < 50 ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}




