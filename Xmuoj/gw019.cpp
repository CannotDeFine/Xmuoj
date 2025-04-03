/*
 * @Author: cdf
 * @Date: 2024-11-07 20:41:21
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-01 17:18:02
 * @Description: xmuoj_奥运奖牌计数
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int gold , sliver, brozen, n;
    cin >> n;
    
    int gold_num = 0, sliver_num = 0, brozen_num = 0;
    while (n--) {
        cin >> gold >> sliver >> brozen;
        gold_num += gold;
        sliver_num += sliver;
        brozen_num += brozen;
    }

    printf("%d %d %d %d", gold_num, sliver_num, brozen_num, gold_num + sliver_num +brozen_num);

    return 0;
}