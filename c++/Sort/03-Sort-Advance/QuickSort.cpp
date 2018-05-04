#include <iostream>
#include <algorithm>

using namespace std;
void echo(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int __Partition(int arr[], int l, int r){
    int v = arr[l];
    int j = l; 

    for(int i=l+1 ; i<=r ; i ++){
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
            echo(arr , 10);
        }
    }
    swap( arr[l] , arr[j]);
    return j;
}
 
void __QuickSort(int arr[] , int l , int r){
    if( l >= r ){ return; }

    int p = __Partition(arr, l, r);
    __QuickSort(arr, l, p-1 );
    __QuickSort(arr, p+1, r);
}
void QuickSort(int arr[] , int n){
    __QuickSort(arr , 0 , n-1);
}



int main() {
    int arr[10] = {1,5,3,1,2,3,5,8,7,1};
    QuickSort(arr , 10);
    for(int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}