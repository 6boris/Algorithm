#include <iostream>
using namespace std;
main()
{
    string str = "We Are Happy";

    // 统计空格字数
    int spacenum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            spacenum++;
        }
    }
    int indexold = str.length() - 1;
    int newlength = str.length() + spacenum * 2;
    int indexnew = newlength - 1;
    for (; indexold >= 0 && indexold < newlength; --indexold)
    {
        if (str.charAt(indexold) == ' ')
        { //
            str.setCharAt(indexnew--, '0');
            str.setCharAt(indexnew--, '2');
            str.setCharAt(indexnew--, '%');
        }
        else
        {
            str.setCharAt(indexnew--, str.charAt(indexold));
        }
    }
    return str.toString();
}