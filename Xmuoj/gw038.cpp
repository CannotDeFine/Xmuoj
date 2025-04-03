/*
 * @Author: cdf
 * @Date: 2024-11-08 20:16:45
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 00:13:07
 * @Description: xmuoj_第i位取反
 */

#include<bits/stdc++.h>
using namespace std;

int bitManipulation2(int n, int i) {
    return n ^ (1 << i);
}

int main()
{
    int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}