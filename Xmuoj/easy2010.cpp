/*
 * @Author: cdf
 * @Date: 2024-11-10 14:11:25
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-10 14:21:14
 * @Description: xmuoj_水仙花数
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int l, r;
    
    while (cin >> l >> r) {
        
        bool flag = false;
        for (int i = l; i <= r; i++) {

            int temp = i, sum = 0;
            while (temp) {
                sum += pow(temp % 10, 3);
                temp /= 10;
            }

            if (sum == i) {
                if (!flag) cout << i ;
                else cout << ' ' << i;
                flag = true;
            }

        }
        if (!flag) cout << "no";
        cout << endl; 
    }

    return 0;
}