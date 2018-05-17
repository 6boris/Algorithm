#include <malloc.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*
    1.先选择
       f =  arr[i] + s(i+1 , j)
       f =  arr[j] + s(i , j-1)
    2.后选择

*/
class Solution {
 public:
  int win1(vector<int> arr) {
    if (arr.empty() || arr.size() == 0) {
      return 0;
    }
    return fmax(f(arr, 0, arr.size() - 1), s(arr, 0, arr.size() - 1));
  }

  int win2(vector<int> arr) {
    if (arr.empty() || arr.size() == 0) {
      return 0;
    }
    vector<vector<int>> f(arr.size(), vector<int>(arr.size()));
    vector<vector<int>> s(arr.size(), vector<int>(arr.size()));
    initArrar(f);
    initArrar(s);

    for (int j = 0; j < arr.size(); j++) {
      f[j][j] = arr[j];
      for (int i = j - 1; i >= 0; i--) {
        f[i].push_back(fmax(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]));
        s[i].push_back(fmin(f[i + 1][j], f[i][j - 1]));
      }
    }
    return fmax(f[0][arr.size() - 1], s[0][arr.size() - 1]);
  }

  int f(vector<int> arr, int i, int j) {
    if (i == j) {
      return arr[i];
    }
    return fmax(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
  }
  int s(vector<int> arr, int i, int j) {
    if (i == j) {
      return 0;
    }
    return fmin(f(arr, i + 1, j), f(arr, i, j - 1));
  }

  void initArrar(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; i < arr[i].size(); j++) {
        arr[i][j] = 0;
      }
      cout << endl;
    }
  }
  vector<int> generateRondomArray(int start, int end, int number) {
    vector<int> arr;
    for (int i = 0; i < number; i++) {
      arr.push_back(rand() % (start - end + 1) + start);
    }
    return arr;
  }

  void echo(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
      cout << " " << arr[i];
    }
    cout << endl;
  }

 private:
};

int main() {
  Solution s;
  int testTime = 5000;
  vector<int> arr = s.generateRondomArray(1, 10, 10);
  s.echo(arr);
  cout << s.win1(arr) << endl;
  // cout << s.win2(arr) << endl;
  return 0;
}
