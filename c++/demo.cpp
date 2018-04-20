#include <iostream>
#include <stack>

using namespace std;

int main() {
    int i = 0;
    stack<int> first;
    cout << "size of first: " << first.size() << endl;
    cout <<" demo"<<endl;
    for (int i=0; i<6; i++)
        first.push(i);
    cout << "size of first: " << first.size() << endl;

   int demo = first.top();
   int size = first.size();
    cout<<"--"<<demo;
    cout<<size;

    return 0;

}