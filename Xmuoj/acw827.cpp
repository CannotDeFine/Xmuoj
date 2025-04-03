/*
 * @Author: cdf
 * @Date: 2025-01-06 17:21:26
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-07 18:46:30
 * @Description: 双链表
 */
#include<bits/stdc++.h>
using namespace std;

#define N 10
int e[N], ne[N], pre[N],idx = 1, head = -1,tail = -1;

void print_link(){
    //cout << "Link-list:" ;
    int i;
    for (i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    cout << endl;
    //cout << "head: " << head << ' ' << "tail: " << tail << endl;
}

void add_R(int x) {
    if (head == -1 && tail == -1) {
        e[idx] = x;
        ne[idx] = tail;
        pre[idx] = head;
        head = tail = idx;
        idx ++;
    } 
    else {
        e[idx] = x;
        ne[idx] = -1;
        pre[idx] = tail;
        ne[tail] = idx;
        tail = idx;
        idx ++;
    }
    //print_link();
}

void add_L(int x) {
    if (head == -1 && tail == -1) {
        e[idx] = x;
        ne[idx] = tail;
        pre[idx] = head;
        head = tail = idx;
        idx ++;
    }
    else {
        e[idx] = x;
        ne[idx] = head;
        pre[idx] = -1;
        pre[head] = idx;
        head = idx;
        idx ++;
    }
    //print_link();
}

void remove(int k) {
    if (head == tail) {
        head = tail = -1;
    }
    else if (k == head) {
        pre[ne[k]] = -1;
        head = ne[k];
    }
    else if (k == tail) {
        ne[pre[k]] = -1;
        tail = pre[k];
    }
    else {
        pre[ne[k]] = pre[k];
        ne[pre[k]] = ne[k];
    }
    //print_link();
}

void insert_R(int x, int k) {
    e[idx] = x;
    ne[idx] = ne[k];
    pre[idx] = k;
    
    if (k == tail) {
        tail = idx;
    }
    else {
        pre[ne[k]] = idx;
    }

    ne[k] = idx;
    idx ++;
    //print_link();
}

void insert_L(int x, int k) {

    //cout << pre[k] << ' ' <<ne[pre[k]] << endl;

    e[idx] = x;
    ne[idx] = k;
    pre[idx] = pre[k];
    //cout << pre[idx] << ' ' << ne[idx] << endl;
    if (k == head) head = idx;
    else ne[pre[k]] = idx;
    
    pre[k] = idx;
    idx ++;
    //print_link();
}

int main() {

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;
        
        if (op == "R") {
            int x;
            cin >> x;
            add_R(x); 
        }
        else if (op == "L") {
            int x;
            cin >> x;
            add_L(x);
        }
        else if (op == "D") {
            int k;
            cin >> k;
            remove(k);
        }
        else if (op == "IR") {
            int x, k;
            cin >> k >> x;
            insert_R(x, k);
        }
        else if (op == "IL"){
            int x, k;
            cin >> k >> x;
            insert_L(x, k);
        }
        else {
            cout << "wrong operation!" << endl;
        }
    }

    print_link();
    
    return 0;
}