#include <iostream>
using namespace std;


void Random(int arr[] , int n , int rangeL , int rangeR){
	for(int i=0 ; i<n ; i++){
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	}
}
void __Merge(int arr[] , int l , int mid , int r){
	int aux[r-l+1];
	for(int i=l ; i<=r ; i++){
		aux[i-l] = arr[i];
	}
	int i = l , j = mid + 1;
	for(int k = l ; k<=r ; k++){
		if(i > mid){
			arr[k] = aux[j-l];
			j++;
		}
		if(j > r){
			arr[k] = aux[i-l];
		}
		if(aux[i-l] <= aux[j-l]){
			arr[k] = aux[i-l];
			i++;
		}else{
			arr[k] = aux[j-1];
			j++;
		}
	}
}
void __MergeSort(int arr[] , int l ,int r){
	if(l >= r){
		return;
	}

	int mid = (l + r) / 2;
	__MergeSort(arr , l , mid);
	__MergeSort(arr , mid+1 , r);
	__Merge(arr , l , mid , r);

}

void MergeSort(int arr[] , int n){
	__MergeSort(arr , 0 , n-1);
}

int main(){
	int arr[10];
	Random(arr , 10 , 1 , 100);
	for(int i=0 ; i<10 ; i++)
		cout<<arr[i]<<" ";	
	MergeSort(arr , 10);
	cout<<endl;
	for(int i=0 ; i<10 ; i++)
		cout<<arr[i]<<" ";	
	return 0;
}