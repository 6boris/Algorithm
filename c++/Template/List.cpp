#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <malloc.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

/*输入一个链表，输出该链表中倒数第k个结点。*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
    int val;
    struct ListNode* next;
    // ListNode(int x);
};

class Solution {
public:
    // 在链表头部插入节点
    void InsertHead(ListNode* pListHead)
    {
    }

    // 在链尾部部插入节点
    void Insert(ListNode* pListHead)
    {
    }

    // 删除第几个节点
    void Remove(ListNode* pListHead, int index)
    {
        ListNode* p = new ListNode();
    }

    // 获取链表长度
    int getLength(ListNode* pListHead)
    {
        int len = 0;
        while (pListHead != NULL) {
            len++;
            pListHead = pListHead->next;
        }
        return len;
    }

    // 链表翻转
    ListNode* Reverse(ListNode* pListHead)
    {
        if (pListHead == NULL) {
            return NULL;
        }
        ListNode* pNode = pListHead;
        ListNode* pPrev = NULL;
        while (pNode != NULL) {
            ListNode* pNext = pNode->next;

            pNode->next = pPrev;
            pPrev = pNode;

            pNode = pNext;
        }
        return pPrev;
    }

    // 查找节点位置
    int Find(ListNode* pListHead, int val)
    {
        int index = 1;
        ListNode* p = pListHead;
        while (p != NULL) {
            if (p->val == val) {
                // cout << p->val << endl;
                return index;
            }
            p = p->next;
            index++;
        }
        return -1;
    }

    void Print(ListNode* pListHead)
    {
        if (pListHead == NULL) {
            cout << "LinkList is empty" << endl;
            return;
        }
        ListNode* temp = pListHead;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode* Init(int length)
    {
        ListNode* pListHead = new ListNode();
        ListNode* p = pListHead;

        while (--length > 0) {
            p->val = getRandom(1, 20);
            p->next = createNode(getRandom(1, 20));
            p = p->next;
        }
        return pListHead;
    }

private:
    ListNode* createNode(int val)
    {
        ListNode* p = new ListNode();
        p->val = val;
        p->next = NULL;
        return p;
    }
    int getRandom(int start, int end)
    {
        return rand() % (start - end + 1) + start;
    }
};
int main()
{
    Solution s;
    ListNode* Head = s.Init(10);
    s.Print(Head);
    cout << s.getLength(Head) << endl;
    s.Print(s.Reverse(Head));
    return 0;
}
