/*
 * @Author: cdf
 * @Date: 2025-01-08 19:06:19
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 19:41:03
 * @Description: 单调队列试炼之最大子序和
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
int que[N], head = 0, tail = -1;

int main () {
	int n, k;
	cin >> n >> k;
	
	// 计算前缀和
	int nums[n], sum[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (i == 0) sum[i] = nums[i];
		else sum[i] = nums[i] + sum[i - 1];							// nums数组完全可以不用
	}
	
	// 计算sum数组的滑动窗口的最小值数组
	int ans = INT_MIN, rem[n];
	rem[0] = 0;														//  细节：rem[0] 特殊处理为 0
	for (int i = 0; i < n; i++) {
		if (head <= tail && i - que[head] > k ) head++;			    // 注意sum数组的滑动窗口应该是k + 1 
		while (head <= tail && sum[que[tail]] >= sum[i]) tail--;    // 比当前队列尾部大的退队列
		que[++tail] = i;
		if (i != 0 ) rem[i] = sum[que[head]];
		ans = max (ans, sum[i] - rem[i]);
	}
	
	cout << ans <<  endl;
	return 0;
}
