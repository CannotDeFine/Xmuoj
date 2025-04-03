/*
 * @Author: cdf
 * @Date: 2025-03-07 10:37:24
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 10:40:50
 * @Description: 统计工龄 -- 哈希表
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    map<int, int> hash;
    while (n--)
    {
        int age;
        cin >> age;

        hash[age]++;
    }

    for (auto & elem: hash)
    {
        cout << elem.first << ':' << elem.second << endl;
    }

    return 0;
 }