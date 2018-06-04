#include<iostream>
using namespace std;

class HeapSort {
public:
    void swap(int* A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
     
    void sift_minHeap(int* A, int n, int begin, int end)
    {
        int parent = begin, child = 2*parent+1;   //parent为子树的根，child是parent的左孩子
        int value = A[parent];                   //记录子树根的值
         
        while(child <= end)                            //沿较小值孩子结点向下筛选
        {
            if(child < end && A[child] > A[child + 1])    //记录孩子值较小者
                child++;
            if(value > A[child])
            {
                A[parent] = A[child];
                parent = child;
                child = 2*parent + 1;
            }
            else break;
        }
        A[parent] = value;
    }
     
    void sift_maxHeap(int* A, int n, int begin, int end)
    {
        int parent = begin, child = 2*parent+1;   //parent为子树的根，child是parent的左孩子
        int value = A[parent];                   //记录子树根的值
         
        while(child <= end)                            //沿较小值孩子结点向下筛选
        {
            if(child < end && A[child] < A[child + 1])    //记录孩子值较小者
                child++;
            if(value < A[child])
            {
                A[parent] = A[child];
                parent = child;
                child = 2*parent + 1;
            }
            else break;
        }
        A[parent] = value;
    }
     
    int* heapSort(int* A, int n) {
        // write code here
         
        for(int i = n/2 - 1; i >= 0; i--)
        {
            sift_maxHeap(A, n, i, n-1);
        }
         
        for(int i = n-1; i>0; i--)
        {
            swap(A, 0, i);
            sift_maxHeap(A, n, 0, i-1);
        }
         
        return A;
    }
};


int main(){
    HeapSort h;
    int arr[] = {4, 3, 4, 3, 9, 5, 4, 3, 2, 1};
    h.heapSort(arr, 10);

  for (int i = 0; i < 10; i++) {
      cout<<arr[i]<<" ";
  }
  return 0;
    return 0;
}