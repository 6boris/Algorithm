#include <iostream>
using namespace std;
/* 创建一个单链表 */
struct ListNode
{
    int m_key;
    ListNode *next;
};
void createList(ListNode *pHead)
{
    ListNode *p = pHead;
    for (int i = 1; i < 10; ++i)
    {
        ListNode *pNewNode = new ListNode;
        pNewNode->m_key = i; // 将新节点的值赋值为i
        pNewNode->next = NULL;
        p->next = pNewNode; // 上一个节点指向这个新建立的节点
        p = pNewNode;       // p节点指向这个新的节点
    }
}

void printList(ListNode *pHead)
{
    ListNode *p = pHead;
    while (p->next != NULL)
    {
        cout << p->m_key << endl;
        p = p->next;
    }
}

int main()
{
    ListNode *head = NULL;
    head = new ListNode;
    head->m_key = 0;
    head->next = NULL;
    createList(head);
    printList(head);

    return 0;
}