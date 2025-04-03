/*
 * @Author: cdf
 * @Date: 2025-01-07 18:48:56
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-07 19:03:12
 * @Description: 模拟栈
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int sta[N], top = -1;

void push_x(int x) {
    sta[++top] = x;
}

void pop_x() {
    top --;
}

void empty() {
    if (top == -1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void query() {
    cout << sta[top] << endl;
}

int main() {

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            push_x(x);
        }
        else if (op == "pop") {
            pop_x();
        }
        else if (op == "empty") {
            empty();
        }
        else if (op == "query") {
            query();
        }
        else cout << "wrong operation!" << endl;
    }

    return 0;
}