#include<iostream>
using namespace std;

class QuickSort {
public:
    int* quickSort(int* A, int n) {
        Sort(A , 0 , n-1);
        return A;
    }

    void Sort(int s[], int l, int r)  
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
            Sort(s, l, i - 1); // 递归调用  
            Sort(s, i + 1, r);  
        }  
    } 
};


int main(){
    QuickSort q;
    int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
    q.quickSort(arr, 10);

  for (int i = 0; i < 10; i++) {
      cout<<arr[i]<<" ";
  }
  return 0;
    return 0;
}