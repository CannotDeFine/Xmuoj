/*
 * @Author: cdf
 * @Date: 2024-11-08 20:21:16
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 20:27:51
 * @Description: xmuoj_左边i位全部取反
 */

#include<bits/stdc++.h>
using namespace std;

int bitManipulation3(int n, int i) {
    return n ^ ((1ULL << i) - 1);
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}