/*
 * @Author: cdf
 * @Date: 2025-01-05 17:07:32
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-05 17:36:13
 * @Description: 约瑟夫问题
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node * next;
};

struct Node * InitLinklist(int n)
{
    struct Node * head = new struct Node;   // 头插法创建 单循环链表
    struct Node * tail;
    for (int i = n; i >= 1; i--) {
        struct Node * temp = new struct Node;
        temp -> val = i;
        temp -> next = head -> next;
        head -> next = temp;
        if (i == n ) tail = temp;
    } 

    tail -> next = head -> next;

    return head -> next;
};


void solve (int n, int m) {
    struct Node * head = InitLinklist(n);

    int count = 0;
    struct Node * p = head;

    while (p -> next != head) {     // 找p的前驱结点
        p = p -> next;
    }
    struct Node * pre = p;
    p = pre -> next;

    while (count != n - 1) {     // 找应该删除的结点
        int temp = 1;
        while (temp != m) {
            p = p -> next;
            pre = pre -> next;
            temp ++;
        }

        pre -> next = p -> next;
        delete p;    // 这边应该释放一下内存
        p = pre -> next;

        count ++;
    }

    cout << p -> val << endl;   // 输出之后应该释放一下内存
    delete p;
}

int main() {

    while (1) {
        int n, m;

        cin >> n >> m;
        if (n == 0 && m == 0) break;
        else solve (n, m); 
    }

    return 0;
}