/*
 * @Author: cdf
 * @Date: 2025-04-22 10:18:11
 * @LastEditors: cdf
 * @LastEditTime: 2025-04-22 10:28:43
 * @Description: 传送能量
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums;
    int num;
    while (cin >> num) nums.push_back(num);

    vector<bool> flag(nums.size(), false);
    flag[0] = true;
    for (int i = 0 ; i < nums.size() - 1; i++)
    {
        if (!flag[i]) continue; 
        if (flag[nums.size() - 1]) break;

        for (int j = 1; j <= nums[i] && (j + i) < nums.size(); j++)
        {
            flag[i + j] = true;
        }
    }

    if (flag[nums.size() - 1]) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}