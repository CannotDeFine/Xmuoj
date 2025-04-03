/*
 * @Author: cdf
 * @Date: 2025-03-07 20:31:53
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 21:53:25
 * @Description: 英雄排名
 */

#include <bits/stdc++.h>
using namespace std;

// 归并排序的一部分，用于合并两个有序数组，并计算正确排名对数
long long mergeAndCount(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long count = 0;
    
    // 合并两个有序部分，同时统计正确的排名对数
    while (i < mid && j <= right) {
        if (nums[i] > nums[j]) {   // 计算正确排名
            count += (mid - i);    // 左侧 [i, mid-1] 区间内所有元素都比 nums[j] 大
            temp[k++] = nums[j++];
        } else {
            temp[k++] = nums[i++];
        }
    }
    
    // 处理剩余元素
    while (i < mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    // 复制回原数组
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
    
    return count;
}

// 归并排序，同时计算正确排名对数
long long mergeSortAndCount(vector<int>& nums, vector<int>& temp, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    long long count = 0;
    
    // 递归对左右部分进行排序并统计排名对数
    count += mergeSortAndCount(nums, temp, left, mid);
    count += mergeSortAndCount(nums, temp, mid + 1, right);
    
    // 归并两个有序部分并计算排名对数
    count += mergeAndCount(nums, temp, left, mid + 1, right);
    
    return count;
}

// 计算正确排名对数的主函数
long long countCorrectRankings(vector<int>& nums) {
    vector<int> temp(nums.size()); // 临时数组用于归并排序
    return mergeSortAndCount(nums, temp, 0, nums.size() - 1);
}

int main() {
    int n;
    cin >> n; // 读取英雄数量
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // 读取英雄战斗力排名
    }
    
    cout << countCorrectRankings(nums) << endl; // 输出正确的排名对数
    
    return 0;
}
