/*
 * @Author: cdf
 * @Date: 2025-03-04 17:15:42
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-04 17:49:35
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
    node(char ch) : data(ch), left(nullptr), right(nullptr) {}
};

// 中序遍历打印二叉树
void printInorder(node *t)
{
    if (!t) return;
    printInorder(t->left);
    cout << t->data;
    printInorder(t->right);
}

// 根据前序遍历字符串创建二叉树
node* createtree(string &str, int &now)
{
    if (now >= str.size()) return nullptr;
    if (str[now] == '#')  // 空节点
    {
        now++;
        return nullptr;
    }

    // 创建当前节点
    node *t = new node(str[now]);
    now++;

    // 递归创建左右子树
    t->left = createtree(str, now);
    t->right = createtree(str, now);

    return t;
}

// 交换每个结点的左右孩子
void swapTheleftAndright(node *t)
{
    if (!t) return;

    swap(t->left, t->right);  // 直接使用 swap 交换左右子树

    swapTheleftAndright(t->left);
    swapTheleftAndright(t->right);
}

// 释放二叉树的内存
void freeTree(node *t)
{
    if (!t) return;
    freeTree(t->left);
    freeTree(t->right);
    delete t;
}

int main()
{
    string preorder;
    cin >> preorder;
    int now = 0;

    // 创建二叉树
    node *head = createtree(preorder, now);
    
    // 打印原始二叉树的中序遍历
    printInorder(head);
    cout << endl;
    
    // 交换左右子树
    swapTheleftAndright(head);

    // 打印交换后的二叉树的中序遍历
    printInorder(head);
    cout << endl;

    // 释放内存
    freeTree(head);

    return 0;
}
