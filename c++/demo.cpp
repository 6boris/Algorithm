#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 15;

int main()
{
    int v[N] = { 0, 8, 10, 6, 3, 7, 2 };
    int w[N] = { 0, 4, 6, 2, 2, 5, 1 };

    int m[N][N];
    int n = 6, c = 12;
    memset(m, 0, sizeof(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (j >= w[i])
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);

            else
                m[i][j] = m[i - 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}