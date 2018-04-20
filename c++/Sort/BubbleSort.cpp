#include <iostream>
using namespace std;

void BubbleSort(int arr[] , int n);


int main ()
{
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


void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}