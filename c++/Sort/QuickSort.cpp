#include<iostream>
using namespace std;

void QuickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        QuickSort(s, l, i - 1); // 递归调用  
        QuickSort(s, i + 1, r);  
    }  
}  

int main(){
    int arr[10] = {1,2,3,4,5,22,3,7,1,2};
    for( int i=0 ; i<10 ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    QuickSort( arr , 0 , 9 );
    for( int i=0 ; i<10 ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}