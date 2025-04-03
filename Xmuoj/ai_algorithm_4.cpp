/*
 * @Author: cdf
 * @Date: 2025-03-08 13:46:22
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-08 15:15:11
 * @Description: 梦幻料理学院
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << 3 << endl;
        } else {
            long long power = 1LL << n; // 计算 2^n
            if (n % 2 == 1) {
                cout << power - 2 << endl;
            } else {
                cout << power + 2 << endl;
            }
        }
    }
    return 0;
}

 /* 回溯超时
 #include <bits/stdc++.h>
 using namespace std;

 const int N = 51;
 unsigned long long totalcount = 0;
 vector<int> rem ={0 , 1, 2};

 void count_num(vector<int> &temp, int n)
 {
    if (n == 1)
    {
        totalcount = 3;
        return;
    }
    if (n == 2)
    {
        totalcount = 6;
        return;
    }

    if (temp.size() >= 2 && temp[temp.size() - 1] == temp[temp.size() - 2]) return;
    if (temp.size() == n)
    {
        if (temp[temp.size() - 1] == temp[0]) return;
        totalcount ++;
        return ;
    }

    for (int i = 0; i < 3; i++)
    {
        temp.push_back(rem[i]);
        count_num(temp, n);
        temp.pop_back();
    }
    
 }

 int main()
 {
    int n;
    while (cin >> n)
    {
        totalcount = 0;
        vector<int> temp;
        count_num(temp, n);
        cout << totalcount << endl;
    }

    return 0;
 }
*/