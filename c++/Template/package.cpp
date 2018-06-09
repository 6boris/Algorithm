#include <algorithm>
#include <iostream>
using namespace std;

//背包容量
#define CAPACITY 10
// 物品数量
#define NUM 5
// 长度多除一个好处理
int optimal[NUM][CAPACITY] = { 0 };

int weight[NUM] = { 4, 5, 6, 2, 2 };
int value[NUM] = { 6, 4, 5, 3, 6 };

void echo()
{
    for (int i = 0; i <= NUM; i++) {
        for (int j = 0; j <= CAPACITY; j++) {
            cout << optimal[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < CAPACITY; j++) {
            if (weight[i] < j) {
                optimal[i][j] = max(optimal[i - 1][j], optimal[i - 1][j - weight[i]] + value[i]);
            } else {
                optimal[i][j] = optimal[i - 1][j];
            }
        }
    }
    cout << endl;
    echo();
    cout << "The optimal solution is: " << optimal[NUM - 1][CAPACITY - 1] << endl;
    return 0;
}
