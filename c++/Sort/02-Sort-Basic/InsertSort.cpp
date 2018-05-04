#include<iostream>
#include<ctime>
using namespace std;




void InsertSort(int arr[] , int n ){
    for( int i = 1 ; i < n ; i++ ){
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j-- ){
            swap( arr[j] , arr[j-1] );
        }
    }
}

void InsertSortd(int arr[] , int n ){
    for( int i = 1 ; i < n ; i++ ){
        int e = arr[i] , j;
        for( j = i ; j > 0 && arr[j-1] > e ; j-- ){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}


int main(){

    double start1 , finish1 , start2 , finish2 ; /* 定义开始的时间和结束的时间 */  
    int num = 10000;
    int arr1[num];
    Random(arr1 , num , 1 , 5);
    
    int arr2[num];
    Random(arr2 , num , 1 , 5);

    start1 = (double)clock(); 
    InsertSort(arr1 , num);
    finish1 = (double)clock();  
    
    start2 = (double)clock();
    InsertSortd(arr2 , num);
    finish2 = (double)clock();  

    // for( int i = 0 ; i < num ; i++ )
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    printf("%.4fms\n", (finish1 - start1));  
    printf("%.4fms\n", (finish2 - start2));  
    return 0;
}