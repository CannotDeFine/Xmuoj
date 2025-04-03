/*
 * @Author: cdf
 * @Date: 2025-01-04 17:17:13
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-05 16:54:37
 * @Description: 装箱问题
 */

#include<bits/stdc++.h>
using namespace std;

void process(vector<int> & loads) {

    //vector<int> loads(6, 0);
    //for (int i = 0; i < 6; i++) cin >> loads[i];

    int res = loads[5];
    if (loads[4] != 0) {
        res += loads[4];

        int remain = loads[4] * 11;
        if (loads[0] <= remain) {
            loads[0] = 0;
        }
        else {
            loads[0] -= remain;
        }
    }
    if (loads[3] != 0) {
        res += loads[3];
        //cout << "2:" << res << endl;
        int remain = loads[3] * 20;
        if (loads[1] * 4 <= remain) {
            if (loads[0] <= remain - loads[1] * 4) {
                loads[0] = 0;
            }
            else loads[0] = remain - loads[1] * 4 - loads[0]; 
            loads[1] = 0;
        }
        else {
            loads[1] -= loads[3] * 5;
        }
    }
    if (loads[2] != 0) {
        res += ceil(loads[2] * 1.0 / 4);
       // cout << "3:" << res << "res:" << ceil(loads[2] * 1.0 / 4) << "loads[2]:" <<  loads[2] << endl;

        int temp = 4 - loads[2] % 4; // 说明此时还是剩下一块
        int remain = 9 * temp;
        
        if (temp == 1) {
            if (loads[1] != 0) {
                loads[1] -= 1;
                remain -= 4;
            }
            if (loads[0] > remain) {
                loads[0] -= remain;
            }
            else {
                loads[0] = 0;
            }
        }
        if (temp == 2) {
            if (loads[1] >= 3) {
                loads[1] -= 3;
                remain -= 12;
            }
            else {
                remain -= loads[1] * 4;
                loads[1] = 0;
            }
            if (loads[0] > remain) {
                loads[0] -= remain;
                remain = 0;
            }
            else {
                loads[0] = 0;
                remain -= loads[0];
            }
        }
        if (temp == 3) {
            if (loads[1] <= 5) {
                loads[1] = 0;
                remain -= loads[1] * 4;
            }
            else {
                loads[1] -= 5;
                remain -= 20;
            }
            if (loads[0] >= remain) {
                loads[0] -= remain;
                remain = 0;
            }
            else {
                loads[0] = 0;
            }
        }
    }
    if (loads[1] !=0 ) {
        res += ceil(loads[1] * 1.0 / 9);
        //cout << "4:" << res << endl;

        int temp = 9 - loads[2] % 9;
        int remain = temp * 4;
        if (temp != 9) {
            if (loads[0] >= remain) {
                loads[0] -= remain;
            }
            else loads[0] = 0;
        } 
    }
    if (loads[0] != 0) {
        res += ceil(loads[0] * 1.0 / 36);
       // cout << "5:" << res << endl;
    }

    cout << res << endl;
}

int main () {
    vector <int> loads(6,0);
    bool flag = true;

    while (1) {
        flag = false;
        for (int i = 0; i < 6; i++) {
            cin >> loads[i];
            if (loads[i] != 0) flag = true; 
        }
        if (flag) process(loads);
        else break;
    }
    return 0;
}