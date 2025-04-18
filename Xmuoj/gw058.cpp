/*
 * @Author: cdf
 * @Date: 2025-03-28 16:57:33
 * @LastEditors: cdf
 * @LastEditTime: 2025-04-18 23:22:23
 * @Description: 从字符串中取数字
 */


#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
    static char * p = NULL;
    if (str) p = str;

    if (p == NULL) return -1;

    char * end;
    while (*p) {
        double val = strtod(p, &end);
        if (end == p) {
            ++p;  // 跳过非数字字符
        } else {
            if (val > 0) {
                p = end;
                return val;
            } else {
                p = end;
            }
        }
    }
    return -1;  // 读完或无正数
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}