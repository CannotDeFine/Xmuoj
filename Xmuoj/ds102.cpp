/*
 * @Author: cdf
 * @Date: 2025-02-14 11:29:06
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-15 14:48:56
 * @Description: 链表去重
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, head;
    cin >> head >> n;

    // 输入, 将下标和地址进行绑定
    int sta[n + 4], ne[n + 4], num[n + 4];
    unordered_map<int,int> hash;
    for (int i = 0; i < n; i++)
    {
        cin >> sta[i] >> num[i] >> ne[i];
        hash[sta[i]] = i;
    }

    // 用于数字统计
    unordered_map<int,int> num_cnt;
    num_cnt[abs(num[hash[head]])]++;

    // 遍历结点
    int pre = head;
    int p = ne[hash[head]];

    // 删除所用参数
    bool is_thefirst = true;
    int head2,deletep;
    
    while (p != -1)
    {
        // 如果已经存在值
        if (num_cnt.count(abs(num[hash[p]])))
        {
            // 记录需要删除的第一个结点
            if (is_thefirst)
            {
                head2 = p;
                deletep = head2;

                ne[hash[pre]] = ne[hash[p]];
                p = ne[hash[p]];

                ne[hash[deletep]] = -1;
                is_thefirst = false;
            }
            else // 普通的删除处理
            {
                ne[hash[deletep]] = p;
                deletep = p; 
                
                ne[hash[pre]] = ne[hash[p]];
                p = ne[hash[p]];

                ne[hash[deletep]] = -1;
            }
        }
        else  // 输入值未出现过
        {
            num_cnt[abs(num[hash[p]])]++;
            pre = ne[hash[pre]];
            p = ne[hash[p]];
        }
    }

    // 输出已经处理后的链表
    p = head;
    while (p != -1)
    {
        cout << setw(5) << setfill('0') << sta[hash[p]] << ' ' << num[hash[p]] << ' ' << setw(5) << setfill('0') << ne[hash[p]] << endl;
        p = ne[hash[p]];
    }

    // 输出删除的链表
    deletep = head2;
    while (deletep != -1)
    {
        cout << setw(5) << setfill('0') << sta[hash[deletep]] << ' ' << num[hash[deletep]] << ' ' << setw(5) << setfill('0') << ne[hash[deletep]] << endl;
        deletep = ne[hash[deletep]];
    }

    return 0;
}