#include<iostream>
using namespace std;

int main(){
    int n;
    int sum = 0;

    cin>>n;
    char a[n];
    cin>>a;

    for( int i=0 ; i<n-1 ; i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i'|| a[i]=='o'|| a[i]=='u'){
            if(a[i+1]=='a' || a[i+1]=='e' || a[i+1]=='i'|| a[i+1]=='o'|| a[i+1]=='u'){
                sum += 1;
                // cout<<a[i]<<"-"<<a[i+1]<<endl;
            }
        }
    }
    cout<<sum;
    return 0;
}
