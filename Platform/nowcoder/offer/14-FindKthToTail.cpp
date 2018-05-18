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
    struct ListNode* next = NULL;
    // ListNode(int x);
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        int len = 0;
        ListNode* p = pListHead;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        if (k > len)
            return NULL;
        int i = 1;
        p = pListHead;
        while (i < len - k + 1) {
            p = p->next;
            i++;
        }
        return p;
    }
    ListNode* createNode(int val)
    {
        ListNode* p = new ListNode();
        p->val = val;
        p->next = NULL;
        return p;
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
    cout << s.FindKthToTail(Head, 11)->val << endl;
    return 0;
}
