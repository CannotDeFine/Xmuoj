/*
 * @Author: cdf
 * @Date: 2024-11-09 19:46:12
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 20:01:37
 * @Description: xmuoj_第几天？
 */

#include <bits/stdc++.h>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算该日期是该年的第几天
int dayOfYear(int year, int month, int day) {
    // 每个月的天数
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 如果是闰年，将二月设为29天
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    
    int dayOfYear = 0;
    // 累加前几个月的天数
    for (int i = 0; i < month - 1; ++i) {
        dayOfYear += daysInMonth[i];
    }
    
    // 加上当前月份的天数
    dayOfYear += day;
    
    return dayOfYear;
}

int main() {
    string input;
    while (cin >> input) {
        int year, month, day;
        
        // 格式转换的方式是将分割字符转换成空格，然后使用stringstream方式自然分割即可
        replace(input.begin(), input.end(), '/', ' ');

        stringstream ss(input);
        ss >> year >> month >> day;
        
        cout << dayOfYear(year, month, day) << endl;
    }
    
    return 0;
}

