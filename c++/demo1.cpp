#include<iostream>
using namespace std;

void BubbleSort(int arr[] , int len){
    for(int i=0 ; i<len ; i++){
        for(int j=0 ; j<len-i-1 ; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
        }
    }
}

void SelectSort(int arr[] , int len){

    int i , j , k;
    for( i=0 ; i< len-1 ; i++ ){
        k = i;
        for( j=i+1 ; j<len ; j++ ){
            if(arr[k] > arr[j]){
                k = j;
            }
        }
        swap(arr[i] , arr[k]);
    }
}

void InsertSort(int arr[] , int len){
    int i , j , get;
    for( i=1 ; i<len ; i++ ){
        get = arr[i];
        j = i-1;
        while( j>=0 && arr[j]>get ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = get;
    }
}

void QuickSort(int arr[] , int left , int right){
    if(left < right){
        int key = arr[left];
        int low = left;
        int high = right;

        while( low < high ){
            while( low < high && arr[high] >= key ){
                high--;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] < key){
                low++;
            }
            arr[high] = arr[low];
        }

        arr[low] = key;
        QuickSort(arr , left , low - 1);
        QuickSort(arr , low + 1 , right);
    }
}


int main(){

    int arr[10] = {1,5,4,3,2,6,9,8,7,10};
    for(int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    QuickSort(arr , 0 , 9);

    for(int i=0 ; i<10 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;



    return 0;
}