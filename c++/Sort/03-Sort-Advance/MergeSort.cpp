#include<iostream>

using namespace std;




void Random(int arr[] , int n , int rangeL , int rangeR){
    for( int i = 0 ; i < n ; i++ ){
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
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

//
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

int main(){
    int num = 20;

    // int arr[num];
    // Random(arr , num , 1 , 1000);

    // MergeSort(arr , num);
    // for( int i=0 ; i<num ; i++ )
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    return 0;
}