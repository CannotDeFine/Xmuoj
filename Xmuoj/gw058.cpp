/*
 * @Author: cdf
 * @Date: 2025-01-01 11:37:08
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-01 15:04:25
 * @Description: 从字符串中取数字
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

double GetDoubleFromString(char *str)
{
    static char *currentPosition = nullptr; // 静态变量，用于保存当前字符串解析位置

    // 如果传入的 str 不为空，重新初始化解析位置
    if (str != nullptr) {
        currentPosition = str;
    }

    // 如果当前解析位置为空，返回 0 表示结束
    if (currentPosition == nullptr || *currentPosition == '\0') {
        return 0.0;
    }

    // 跳过非数字字符（忽略负号 -）
    while (*currentPosition && !isdigit(*currentPosition) && *currentPosition != '.') {
        currentPosition++;
    }

    // 如果到达字符串结尾，返回 0 表示结束
    if (*currentPosition == '\0') {
        return 0.0;
    }

    // 使用 strtod 提取数字，并更新解析位置
    char *end;
    double result = strtod(currentPosition, &end);
    currentPosition = end;

    return result;
}

/**
 * @brief 主函数
 *
 * 从标准输入读取字符串，提取其中的浮点数，并将其格式化输出到标准输出。
 *
 * @return 返回值为0，表示程序正常结束。
 */
int main()
{
    char line[300];
    while (cin.getline(line, 280)) {
        double n;
        n = GetDoubleFromString(line);
        while (n != 0.0) {
            cout << fixed << setprecision(6) << n << endl;
            n = GetDoubleFromString(nullptr);
        }
    }
    return 0;
}
