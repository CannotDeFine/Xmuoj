/*
 * @Author: cdf
 * @Date: 2025-02-17 14:07:44
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-17 14:34:37
 * @Description: 银行业务队列简单模拟
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    queue<int> a;
    queue<int> b;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
        {
            a.push(nums[i]);
        }
        else
        {
            b.push(nums[i]);
        }
    }

    vector<int> ans;
    while (!a.empty() && !b.empty())
    {
        ans.push_back(a.front());
        a.pop();
        if (!a.empty())
        {
            ans.push_back(a.front());
            a.pop();
        }

        ans.push_back(b.front());
        b.pop();
    }

    while (!a.empty())
    {
        ans.push_back(a.front());
        a.pop();
    }

    while (!b.empty())
    {
        ans.push_back(b.front());
        b.pop();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
        {
            cout << ans[i];
        }
        else
        {
            cout << ' ' << ans[i];
        }
    }
 
    return 0;
 }