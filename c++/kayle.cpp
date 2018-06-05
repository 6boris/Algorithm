#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;
int main()
{
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    string::iterator it = s.begin();

    for (; it != s.end(); it++) {
        cout << *it << " ";
    }
}