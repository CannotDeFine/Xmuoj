/*
 * @Author: cdf
 * @Date: 2025-02-16 13:34:46
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-16 13:49:30
 * @Description: 最长连续递增子序列
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    int n;
    cin >> n;

    vector<int> nums(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int sta = 0, maxlen = 0;
    int i = 0;
    while (i < n)
    {
        int temp = 1, rem = i;
        while (nums[i + 1] > nums[i])
        {
            i ++;
            temp ++;
        }

        if (temp > maxlen)
        {
            sta = rem;
            maxlen = temp;
        }
        i++;
    }

    for (int i = sta; i < sta + maxlen; i ++)
    {
        cout << nums[i] << ' ';
    }
 
    return 0;
 }