/*
 * @Author: cdf
 * @Date: 2025-03-07 22:21:59
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-08 16:59:55
 * @Description: 星海信息序列
 */
 
// 这个问题实际上是一个翻转对称问题
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, char> myhash;

char is_s(long long now, long long len)  // 使用 long long 类型
{
    if (now == 1) return 's';

    long long mid = len + 1;
    if (now == mid) return 's';
    if (len >= 3 && now == mid - 1) return 'd';
    else if (len >= 3 && now == mid + 1) return 's'; 

    // on the left
    if (now < mid)
    {
        return is_s(now, len / 2);
    }
    else
    {
        long long mirror_now = mid - (now - mid);
        char temp = is_s(mirror_now, len / 2);
        return temp == 's' ? 'd' : 's';
    }  
}

long long counts(long long len, long long left, long long right)  // 使用 long long 类型
{
    long long ans = 0;  // 使用 long long 类型
    for (long long i = left; i <= right; i++)  // 使用 long long 类型
    {
        if (is_s(i, len) == 's') ans++;
    }

    return ans;
}

int main()
{
    long long n;  // 使用 long long 类型
    cin >> n;

    while (n--)
    {
        long long left, right;  // 使用 long long 类型
        cin >> left >> right;

        long long len = 0;  // 使用 long long 类型
        while (len < right)
        {
            len = len * 2 + 1;
        }

        long long ans = 0;  // 使用 long long 类型
        ans = counts(len, left, right);

        cout << ans << endl;
    }

    return 0;
}
