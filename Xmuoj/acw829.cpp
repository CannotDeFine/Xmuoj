/*
 * @Author: cdf
 * @Date: 2025-01-07 20:29:35
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-07 20:33:06
 * @Description: 模拟队列
 */

#include<bits/stdc++.h>
using namespace std;


const int N = 100;
int que[N], front = 0, tail = 0;

void push_x(int x) {
    que[tail] = x;
    tail ++;
}

void pop_x() {
    front ++;
}

void empty() {
    if (front == tail) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void query() {
    cout << que[front] << endl;
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