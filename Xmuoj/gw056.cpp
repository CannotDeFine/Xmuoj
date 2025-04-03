/*
 * @Author: cdf
 * @Date: 2024-11-12 12:44:49
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-12 13:07:57
 * @Description: xmuoj_病人排队
 */

#include<bits/stdc++.h>
using namespace std;

bool cmp (const pair<string,int> &a, const pair<string,int> &b) {
    return a.second > b.second || (a.first < b.first && a.second == b.second);
}

int main() {

    int n;
    cin >> n;

    vector<pair<string,int>> patients(n);
    for (int i = 0; i < n; i++) cin >> patients[i].first >> patients[i].second;

    //sort(patients.begin(), patients.end(), cmp);
    int i = n-1, idx = n-1;
    while (i >= 0) {
        if (patients[i].second < 60) {
            swap(patients[i], patients[idx]);
            idx--;
        }

        i--;
    }

    int count = idx + 1;    // 剩余的老人的数量
    sort (patients.begin(), patients.begin() + count , cmp);

    for (int i = 0; i < n; i++) {
        cout << patients[i].first << endl;
    }
    
    return 0;
}