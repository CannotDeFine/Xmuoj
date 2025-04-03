/*
 * @Author: cdf
 * @Date: 2025-03-10 13:48:37
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 14:06:28
 * @Description: 并查集试炼之合并集合
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;
 int father[N];

 int findf(int num)
 {
    if (father[num] == -1) return num;
    father[num] = findf(father[num]); // 压缩一下路径
    return father[num];
 }

 int main()
 {
    int n, m;
    cin >> n >> m;

    memset(father, -1, sizeof(father));
    while (m--)
    {
        char option;
        cin >> option;

        int a, b;
        cin >> a >> b;

        if (option == 'M')
        {
            int num1 = findf(a);
            int num2 = findf(b);

            if (num1 != num2)
            {
                father[num1] = num2;
            }
        }
        else
        {
            int num1 = findf(a);
            int num2 = findf(b);

            if (num1 == num2) 
            {
                //cout << num1 << ' ' << num2 << endl;
                cout << "Yes" << endl;
            }
            else
            {
                //cout << num1 << ' ' << num2 << endl;
                cout << "No" << endl;
            }
        }
    }

    return 0;
 }