#ifndef INT_SORT_H
#define INT_SORT_H

#include<iostream>
#include<algorithm>
using namespace std;

// 冒泡排序
void BubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j=0 ; j<n-i-1 ; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

// 选择排序
void SelectSort(int arr[] , int len){
    int temp=0 , k=0;
    for(int i=0 ; i<len-1 ; i++ ){
        k=i;
        for(int j=i+1 ; j<len ; j++ ){
            if(arr[k] > arr[j]){ k = j; }
        }
        if(k != i){
            swap(arr[k],arr[i]); 
        }
    }
}


// 插入排序（未优化）
void InsertSort(int arr[] , int n ){
    for( int i = 1 ; i < n ; i++ ){
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j-- ){
            swap( arr[j] , arr[j-1] );
        }
    }
}
// 归并排序
void __Merge(int arr[] , int l , int mid , int r){
    int aux[r-l+1];
    for( int i = l ; i <= r ; i++ ){
        aux[i-l] = arr[i];
    }
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];
        // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
        int i = l, j = mid+1;
        for( int k = l ; k <= r; k ++ ){
            if( i > mid ){  // 如果左半部分元素已经全部处理完毕
                arr[k] = aux[j-l]; j ++;
            }
            else if( j > r ){  // 如果右半部分元素已经全部处理完毕
                arr[k] = aux[i-l]; i ++;
            }
            else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
                arr[k] = aux[i-l]; i ++;
            }
            else{  // 左半部分所指元素 >= 右半部分所指元素
                arr[k] = aux[j-l]; j ++;
            }
        }
    }

void __MergeSort(int arr[] , int l , int r){
    if( l >= r )
        return;
    int mid = (l + r) / 2;
    __MergeSort(arr , l , mid);
    __MergeSort(arr , mid + 1 , r);
    __Merge(arr , l , mid , r);

}


void MergeSort(int arr[] , int n ){
    __MergeSort(arr , 0 , n - 1);
}



// 快速排序
int __Partition(int arr[], int l, int r){
    int v = arr[l];
    int j = l; 

    for(int i=l+1 ; i<=r ; i ++){
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
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



// 获取随机数组
void Random(int arr[] , int n ,int rangeL , int rangeR){
    for( int i = 0 ; i < n ; i++ ){
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
}


#endif //INC_02_MERGE_SORT_INSERTIONSORT_H

