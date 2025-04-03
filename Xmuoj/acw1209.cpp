/*
 * @Author: cdf
 * @Date: 2025-03-12 15:02:04
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 15:36:27
 * @Description: DFS试炼之带分数
 */

 #include <bits/stdc++.h>
 using namespace std;

 vector<int> visited(10, 0);
 vector<int> backup(10, 0);
 int ans = 0;
 int n;

 bool check(int int_num, int fic_num)
 {
    long long b = n * (long long) fic_num - int_num * (long long) fic_num;

    // 下面是对 b 进行拆解，看看是否合法

    for (int i = 1; i <= 9; i++)
    {
        backup[i] = visited[i];
    }

    // 判断是否使用了重复的数字
    while (b)
    {
        int bit = b % 10;
        b /= 10;

        if (bit == 0 || backup[bit] == 1) return false;
        backup[bit] = 1;
    }

    // 判断是否使用了全部的数字
    for (int i = 1; i <= 9; i++)
    {
        if (backup[i] == 0) return false;
    }

    return true;

 }

 void dfs_c(int int_num, int len, int fic_num)
 {
    if (len >= 10) return;
    if (check(int_num, fic_num)) ans ++;

    for (int i = 1; i <= 9; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs_c(int_num, len + 1, fic_num * 10 + i);
            visited[i] = 0;
        }
    }
 }

 void dfs_a (int int_num, int len)
 {
    if (int_num >= n) return;       // 如果整数部分大于 n，直接 return
    if (int_num) dfs_c(int_num, len, 0);

    for (int i = 1; i <= 9; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            dfs_a(int_num * 10 + i, len + 1);
            visited[i] = 0;
        }
    }
 }

 int main()
 {
    cin >> n;

    dfs_a(0, 0);

    cout << ans << endl;

    return 0;
 }
