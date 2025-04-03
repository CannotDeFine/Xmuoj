/*
 * @Author: cdf
 * @Date: 2025-01-01 16:53:59
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-01 16:57:06
 * @Description: 冷血格斗场
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 0;
    cin >> n;

    unordered_map<int,int> hash;
    hash[1] = 1000000000;

    while (n--) {
        int id, power;
        cin >> id >> power;

        int match = 1, min_power = 10000 - power;
        for (auto elem:hash) {
            if (abs(elem.second - power) < min_power) {
                match = elem.first;
                min_power = abs(elem.second - power);
            }
            else if (abs(elem.second - power) == min_power) {
                if (elem.first < match) {
                    match = elem.first;
                    min_power = abs(elem.second - power);
                }
            }
            else continue;
        }

        hash[id] = power;

        cout << id << ' ' << match << endl;
    }

    return 0;
}