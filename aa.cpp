
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    char a[200];
    string b[200];
    static int j = 0;
    int i;
    int count;
    int flag;
    ifstream infile("E:/new.txt ", ios::in); //载入自己设定路径输入文件
    ofstream outfile("E:/old.txt", ios::out); //载入自己设定路径输出文件
    for (i = 0; i < 200; i++) {
        a[i] = infile.get(); //输入文件读取到数组a[]中
    }
    for (i = 0; i < 200; i++) //开始进行数组a[]内字符识别
    {
        switch (a[i]) {
        case '(': //识别符号（
        {
            b[j] = a[i];
            outfile << "<1," << b[j] << ">" << endl;
        }; break;

        case ')': //识别符号）
        {
            b[j] = a[i];
            outfile << "<2," << b[j] << ">" << endl;
        }; break;

        case '+': {
            if (a[i + 1] == '=') //识别符号+=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<3," << b[j] << ">" << endl;
            } else if (a[i + 1] == '+') //识别符号++
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<22," << b[j] << ">" << endl;
            } else //识别符号+
            {
                b[j] += a[i];
                outfile << "<4," << b[j] << ">" << endl;
            }
        }; break;

        case '-': {
            if (a[i + 1] == '=') //识别符号-=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<5," << b[j] << ">" << endl;
            } else if (a[i + 1] == '-') //识别符号--
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<23," << b[j] << ">" << endl;
            } else //识别符号-
            {
                b[j] += a[i];
                outfile << "<6," << b[j] << ">" << endl;
            }
        }; break;
        case '*': {
            if (a[i + 1] == '=') //识别符号*=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<7," << b[j] << ">" << endl;
            } else //识别符号*
            {
                b[j] += a[i];
                outfile << "<8," << b[j] << ">" << endl;
            }
        }; break;

        case '/': {
            if (a[i + 1] == '=') //识别符号 /=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<9," << b[j] << ">" << endl;
            } else if (a[i + 1] == '/') ////识别符号 //
            {
                while (a[i + 2] != '\n') {
                    i++;
                }
                outfile << "<10(1),"
                        << "注释"
                        << ">" << endl;
            } else ////识别符号 /
            {
                b[j] += a[i];
                outfile << "<10," << b[j] << ">" << endl;
            }
        }; break;

        case ';': //识别符号 ；
        {
            b[j] = a[i];
            outfile << "<11," << b[j] << ">" << endl;
        }; break;

        case '<': {
            if (a[i + 1] == '=') //识别符号<=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<12," << b[j] << ">" << endl;
            } else //识别符号 <
            {
                b[j] += a[i];
                outfile << "<13," << b[j] << ">" << endl;
            }
        }; break;

        case '>': {
            if (a[i + 1] == '=') //识别符号 >=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<14," << b[j] << ">" << endl;
            } else //识别符号 >
            {
                b[j] += a[i];
                outfile << "<15," << b[j] << ">" << endl;
            }
        }; break;

        case '=': {
            if (a[i + 1] == '=') //识别符号 ==
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                i++;
                outfile << "<16," << b[j] << ">" << endl;
            } else //识别符号 =
            {
                b[j] += a[i];
                outfile << "<17," << b[j] << ">" << endl;
            }
        }; break;
        }

        if (a[i] == ' ' || a[i] == '\n') //识别符号空格及换行
        {
            j++;
        }

        if (a[i] >= '0' && a[i] <= '9' || a[i] == '.') //识别小数及整数
        {
            b[j] += a[i];

            if (a[i + 1] == ' ' || a[i + 1] == '\n') //识别小数，下面语句进行位数控制
            {
                if (a[i - 1] == '.' || a[i - 2] == '.' || a[i - 3] == '.' || a[i - 4] == '.' || a[i - 5] == '.' || a[i - 6] == '.')
                    outfile << "<18(1)," << b[j] << ">" << endl;
                else
                    outfile << "<18," << b[j] << ">" << endl; //识别整数
            }
        }
        if (a[i] >= 'a' && a[i] <= 'z') //关键字识别，自己添加需要的关键字
        {
            b[j] += a[i];
            if (a[i + 1] == ' ' || a[i + 1] == '\n') {
                if (b[j] == "while")
                    outfile << "<19(1)," << b[j] << ">" << endl;
                else if (b[j] == "int")
                    outfile << "<19(2)," << b[j] << ">" << endl;
                else if (b[j] == "float")
                    outfile << "<19(3)," << b[j] << ">" << endl;
                else if (b[j] == "do")
                    outfile << "<19(4)," << b[j] << ">" << endl;
                else if (b[j] == "public")
                    outfile << "<19(5)," << b[j] << ">" << endl;
                else if (b[j] == "void")
                    outfile << "<19(6)," << b[j] << ">" << endl;
                else if (b[j] == "if")
                    outfile << "<19(7)," << b[j] << ">" << endl;
                else
                    outfile << "<19," << b[j] << ">" << endl; //识别自定义变量
            }
        }
        if (a[i] == ':') {
            if (a[i + 1] == '=') //识别符号 :=
            {
                b[j] = a[i];
                b[j] += a[i + 1];
                outfile << "<20," << b[j] << ">" << endl;
                i++;
            } else //识别符号 :
            {
                b[j] += a[i];
                outfile << "<21," << b[j] << ">" << endl;
            }
        }
    }

    cout << "Success!"; //dos界面显示,则词法识别成功
    outfile.close(); //关闭文件
    infile.close(); //关闭文件
    return 0;
}