/*
 * @Author: cdf
 * @Date: 2025-01-07 20:49:50
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 19:45:04
 * @Description: 滑动窗口_单调队列
 */

// 单调队列找滑动窗口的最大值和最小值

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int que[N] , head = 0, tail = -1;

int main() {

    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    for (int i = 0; i < n; i++) {

        if (head <= tail &&  i - que[head] > k - 1) head++;         // 弹出已经不在窗口中的数字
        while (head <= tail && nums[que[tail]] >= nums[i]) tail--;  // 弹出比新进的数字大的元素
        tail++;
        que[tail] = i;                                              // 新元素入队列
        if (i >= k-1) cout << nums[que[head]] << ' ';
    }
    cout << endl;

    // 初始化队列操作
    head = 0;
    tail = -1;
    memset(que,0,N*sizeof(int));

    for (int i = 0; i < n; i++) {

        if (head <= tail &&  i - que[head] > k - 1) head++;
        while (head <= tail && nums[que[tail]] <= nums[i]) tail--;
        tail++;
        que[tail] = i; 
        if (i >= k-1) cout << nums[que[head]] << ' ';
    }

    return 0;
}