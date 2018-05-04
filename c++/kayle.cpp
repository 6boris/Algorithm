#include <iterator>  
#include <iostream>  
#include <typeinfo>  
#include <list>  
#include <vector>  
#include <algorithm>  
#include <deque>  
#include <string>  



using namespace std;
int main(){
    string s;
    getline(cin,s);
    sort(s.begin() , s.end());
    string::iterator it = s.begin();

    for(; it != s.end() ; it++){
        cout<<*it<<" ";
    }


}