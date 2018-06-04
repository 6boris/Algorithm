/*
	Next数组的定义必须是大写N，因为next在std命名空间中已经存在了。
get_next函数，可以对模板字符串进行操作，从而获得Next数组。kmp函数
则是进行KMP算法匹配。返回的是第一个匹配字符在数组中的位置。下标从
0开始。
    KMP具体算法的学习可以参考july的博客，附网址：
    http://blog.csdn.net/u011411283/article/details/47444523
*/


#include<iostream>
#include<string>
#define MAX 110

using namespace std;

int Next[MAX];

void get_next(string s) {
	int n = s.size();
	Next[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0) {
			j = Next[j];
			if (s[i] == s[j]) {
				Next[i + 1] = j + 1;
				break;
			}
		}
	}
}

void kmp(string s, string t) {
	int n = s.size();
	int m = t.size();
	for (int i = 0, j = 0; i < m; i++) {
		if (j < n && t[i] == s[j]) {
			j++;
		}
		else {
			while (j > 0) {
				j = Next[j];
				if (t[i] == s[j]) {
					j++;
					break;
				}
			}
		}
		if (j == n) {
			// 输出匹配的首字母的下标
			cout << i - n + 1 << endl;
		}
	}
}

int main() {
	// t表示匹配字符串,s表示模板字符串
	// s <= t
	// string s, t;
	string s = "ABABCABAA";
    string t = "ABABABABCABAAB";
	// getline(cin,t);
	// getline(cin, s);
	get_next(s);
    for (int i=0 ; i<20 ; i++) {
        cout<<Next[i]<<" ";
    }
    cout<<Next.size()<<endl;
	// kmp(s, t);

	return 0;
}