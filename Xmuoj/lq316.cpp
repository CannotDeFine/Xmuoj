/*
 * @Author: cdf
 * @Date: 2025-03-14 13:02:09
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 13:24:59
 * @Description: 插入排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 void print_init(vector<int> &nums, int i)
 {
    cout << "  Init:";
    for (int j = 1; j <= i; j++)
    {
        if (j != 1) cout << ' ';
        cout << nums[j];
    }
    cout << endl;
 }

 void print_final(vector<int> &nums, int i)
 {
    cout << "  Final:";
    for (int j = 1; j <= i; j++)
    {
        if (j != 1) cout << ' ';
        cout << nums[j];
    }
    cout << endl;
 }

 void print_moveback(vector<int> &nums, int i)
 {
    cout << "  Move back:";
    for (int j = 1; j <= i; j++)
    {
        if (j != 1) cout << ' ';
        cout << nums[j];
    }
    cout << endl;
 }

 void insert_sort (vector<int> &nums)
 {
    for (int i = 1; i < nums.size(); i++)
    {
        printf("Insert element[%d]:\n", i);   
        print_init(nums, i);
        if (nums[i] < nums[i - 1]) // 如果当前已经是最大值
        {
            int j;
            nums[0] = nums[i];
            for (j = i - 1; nums[j] > nums[0]; j--) 
            {
                nums[j + 1] = nums[j];
                print_moveback(nums, i);
            }
            nums[j + 1] = nums[0];
        }

        print_final(nums, i);
    }
 }

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> nums[i];

    insert_sort(nums);

    return 0;
 }
