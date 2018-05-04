#include <iostream>
#include <iomanip>
#include <cstring>
#include <time.h>  
#include "Sort.h"
using namespace std;

#define ARR_NUM 10000

int main(){
    int num = ARR_NUM;

    double start1 , finish1 
        ,start2 , finish2
        ,start3 , finish3
        ,start4 , finish4
        ,start5 , finish5;

    int arr1[ARR_NUM];
    int arr2[ARR_NUM];
    int arr3[ARR_NUM];
    int arr4[ARR_NUM];
    int arr5[ARR_NUM];

    // 准备测试数据
    Random(arr1 , num , 1 , 1000);
    memcpy(arr2,arr1,sizeof(arr1));
    memcpy(arr3,arr1,sizeof(arr1));
    memcpy(arr4,arr1,sizeof(arr1));
    memcpy(arr5,arr1,sizeof(arr1));


    start1 = (double)clock(); 
    BubbleSort(arr1 , num);
    finish1 =(double)clock();
    cout<<setprecision(6)<<"Bubble Sort: "<<(finish1 - start1)<<"ms"<<endl;

    start2 = (double)clock();
    SelectSort(arr2 , num);
    finish2 =(double)clock();
    cout<<setprecision(6)<<"Select Sort: "<<(finish2 - start2)<<"ms"<<endl;

    start3 = (double)clock();
    InsertSort(arr3 , num);
    finish3 =(double)clock();
    cout<<setprecision(6)<<"Insert Sort: "<<(finish3 - start3)<<"ms"<<endl;

    start4 = (double)clock();
    MergeSort(arr4 , num);
    finish4 =(double)clock();
    cout<<setprecision(6)<<"Merge  Sort: "<<(finish4 - start4)<<"ms"<<endl;

    start5 = (double)clock();
    QuickSort(arr5 , num);
    finish5 =(double)clock();
    cout<<setprecision(6)<<"Quick  Sort: "<<(finish5 - start5)<<"ms"<<endl;



    for(int i=0 ; i<10 ; i++ )
        cout<<arr1[i]<<" ";
    cout<<"-----------"<<endl;

    return 0;
}

