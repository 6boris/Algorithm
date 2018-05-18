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

/*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* next;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    // 根据数组初始化树
    TreeNode* Init(vector<int> arr, int index)
    {
        TreeNode* tree = new TreeNode(arr[index]);
        tree = CreateBinaryTree(tree, arr, 0);
        return tree;
    }

    // 先序遍历
    void PreorderTraverse(TreeNode* pTreeRoot)
    {
        if (pTreeRoot != NULL) {
            cout << pTreeRoot->val << " ";
            PreorderTraverse(pTreeRoot->left);
            PreorderTraverse(pTreeRoot->right);
        }
    }
    // 非递归先序遍历
    void PreorderTraverseNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                cout << pTreeRoot->val << " ";
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            pTreeRoot = pTreeRoot->right;
        }
    }
    // 递归中序遍历
    void MidorderTraverse(TreeNode* pTreeRoot)
    {
        if (pTreeRoot) {
            MidorderTraverse(pTreeRoot->left);
            cout << pTreeRoot->val << " ";
            MidorderTraverse(pTreeRoot->right);
        }
    }
    // 非递归中序遍历
    void MidorderTraverseNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            cout << pTreeRoot->val << " ";
            pTreeRoot = pTreeRoot->right;
        }
    }
    // 递归后序遍历
    void PostorderTraversal(TreeNode* pTreeRoot)
    {
        if (pTreeRoot) {
            PostorderTraversal(pTreeRoot->left);
            PostorderTraversal(pTreeRoot->right);
            cout << pTreeRoot->val << " ";
        }
    }

    // 非递归后序遍历
    void PostorderTraversalNoRecursion(TreeNode* pTreeRoot)
    {
        if (pTreeRoot == NULL) {
            cout << "The Tree is Empty" << endl;
        }
        stack<TreeNode*> stack;
        while (pTreeRoot || !stack.empty()) {
            while (pTreeRoot) {
                stack.push(pTreeRoot);
                pTreeRoot = pTreeRoot->left;
            }
            pTreeRoot = stack.top();
            stack.pop();
            cout << pTreeRoot->val << " ";
            pTreeRoot = pTreeRoot->right;
        }
    }

private:
    // 递归创建树
    /*
        params 
            TreeNode* tree      当前节点
            vector<int> arr     数据
            int index           数据下标

    */
    TreeNode*
    CreateBinaryTree(TreeNode* tree, vector<int> arr, int index)
    {
        if (index == arr.size()) {
            return 0;
        }
        if (arr[index] == -1) {
            tree = NULL;
        } else {
            if (!(tree = (TreeNode*)malloc(sizeof(TreeNode)))) {
                cout << "Malloc ERROR" << endl;
                return 0;
            } else {
                tree->val = arr[index];
                tree->left = CreateBinaryTree(tree->left, arr, ++index);
                tree->right = CreateBinaryTree(tree->right, arr, ++index);
            }
        }
        return tree;
    }
    int getRandom(int start, int end)
    {
        return rand() % (start - end + 1) + start;
    }
};
int main()
{
    Solution s;
    vector<int> data = { 1, 2, 4, -1, -1, -1, 3, 5, -1, -1 };
    // TreeNode* pTreeRoot = s.Init(data, 5);
    TreeNode* pTreeRoot = new TreeNode(1);

    pTreeRoot->left = new TreeNode(3);
    pTreeRoot->right = new TreeNode(5);

    pTreeRoot->left->left = new TreeNode(7);
    pTreeRoot->left->right = new TreeNode(10);

    pTreeRoot->right->left = new TreeNode(13);
    pTreeRoot->right->right = new TreeNode(9);

    pTreeRoot->left->left->left = new TreeNode(15);

    cout << "Pre Traverse Recursion: " << endl;
    s.PreorderTraverse(pTreeRoot);
    cout << "\nPre Traverse No Recursion: " << endl;
    s.PreorderTraverseNoRecursion(pTreeRoot);
    cout << "\nMid Traverse Recursion: " << endl;
    s.MidorderTraverse(pTreeRoot);
    cout << "\nMid Traverse No Recursion: " << endl;
    s.MidorderTraverseNoRecursion(pTreeRoot);
    cout << "\nPost Traverse Recursion: " << endl;
    s.PostorderTraversal(pTreeRoot);
    cout << "\nPost Traverse No Recursion: " << endl;
    s.PostorderTraversalNoRecursion(pTreeRoot);
    return 0;
}
