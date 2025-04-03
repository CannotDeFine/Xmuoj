/*
 * @Author: cdf
 * @Date: 2025-01-12 22:16:21
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-12 23:01:27
 * @Description: Pell数列_打表法
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 32767;
const int L = 1000010; // 跑不起来可能是内存不够,把这个改小

int main()
{
    // 打表
    int nums[L];
    nums[1] = 1;
    nums[2] = 2;
    for (int i = 3; i < L; i++)
    {
        nums[i] = (2 * nums[i - 1] + nums[i - 2]) % N;
    }

    // 输出结果
    int n = 0;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;

        cout << nums[k] << endl;
    }

    return 0;
}