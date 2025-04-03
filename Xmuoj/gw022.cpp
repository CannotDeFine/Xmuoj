/*
 * @Author: cdf
 * @Date: 2024-11-08 10:17:16
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 10:22:40
 * @Description: xmuoj_角谷猜想
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while(1)
    {
        if (n == 1) {
            cout << "End" << endl;
            break;
        }
        else if (n % 2 == 0) {
            printf("%d/2=%d\n", n, n / 2);
            n /= 2;
        }
        else {
            printf("%d*3+1=%d\n", n, n * 3 + 1);
            n = n * 3 + 1; 
        }
    }

    return 0;
}
