/*
 * @Author: cdf
 * @Date: 2025-01-01 16:14:48
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-01 16:32:44
 * @Description: set
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 0;
    cin >> n;

    unordered_map<int,int> hashmap;
    while (n--) {
        int num;
        string op;

        cin >> op >> num;

        if (op == "add") {
            //cout << hashmap[num] << endl;
            hashmap[num]++;
            //hashmap[num].second = true
            cout << hashmap[num] << endl;
        }
        else if (op == "ask") {
            if (hashmap.count(num)) {
                cout << 1 << ' ' << hashmap[num] << endl;
            }
            else cout << 0 << ' ' << 0 << endl;
        }
        else if (op == "del") 
        {
            cout << hashmap[num] << endl;
            hashmap[num] = 0;
        }
        else cout << "wrong opration!" << endl;
        
    }

    return 0;
}