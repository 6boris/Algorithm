#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str = "We Are Happy";
    string::iterator it = str.begin();

    int spacenum = 0;
    int length = 0;
    for (; it < str.end(); it++) {
        cout << *it;
        length++;
    }
    cout << length << endl;
    for (; it < str.end(); it++) {
        string tmp = it[1];
    }

    return 0;
}
