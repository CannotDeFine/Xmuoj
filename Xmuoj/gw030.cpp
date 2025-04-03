/*
 * @Author: cdf
 * @Date: 2024-11-08 16:47:23
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 16:48:07
 * @Description: xmuoj_年龄与疾病
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;  // 读取病人数目
    vector<int> ages(n);

    // 读取每个病人的年龄
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    // 定义年龄段计数器
    int count_0_18 = 0, count_19_35 = 0, count_36_60 = 0, count_61_plus = 0;

    // 遍历年龄并统计对应的年龄段
    for (int age : ages) {
        if (age >= 0 && age <= 18) {
            ++count_0_18;
        } else if (age >= 19 && age <= 35) {
            ++count_19_35;
        } else if (age >= 36 && age <= 60) {
            ++count_36_60;
        } else if (age >= 61) {
            ++count_61_plus;
        }
    }

    // 计算并输出百分比，保留两位小数
    cout << fixed << setprecision(2);
    cout << (count_0_18 * 100.0 / n) << "%" << endl;
    cout << (count_19_35 * 100.0 / n) << "%" << endl;
    cout << (count_36_60 * 100.0 / n) << "%" << endl;
    cout << (count_61_plus * 100.0 / n) << "%" << endl;

    return 0;
}
