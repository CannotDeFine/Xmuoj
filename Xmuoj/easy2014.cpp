/*
 * @Author: cdf
 * @Date: 2024-11-09 19:09:04
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 19:31:08
 * @Description: xmuoj_评委打分
 */


#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;

    while (cin >> n) {
        vector<int> nums(n,0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        sum -= *max_element(nums.begin(), nums.end());
        sum -= *min_element(nums.begin(), nums.end());

        float ans = sum / ((n - 2) * 1.0);  // 这边一定要使用float，double会出现精度问题

        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}