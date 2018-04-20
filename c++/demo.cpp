#include <iostream>
using namespace std;

bool IsOk(char ch)
{
if (ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
{
return true;
} 
else
{
return false;
}
}

int main()
{
char ch;
int count=0;
while ((ch=getchar())!='\n')
{
if (IsOk(ch))
{
count++;
}
}

cout<<"大写元音的总个数: "<<count<<endl;
return 0;
}