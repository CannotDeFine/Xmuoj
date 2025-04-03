/*
 * @Author: cdf
 * @Date: 2025-02-20 16:04:33
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-20 16:16:05
 * @Description: 最长对称子串
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    string s;
    getline(cin, s);

    string ans;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            // 先判断首尾相等
            if (s[i] == s[j]) {
                string temp = s.substr(i, j - i + 1);
                string temp2 = temp;
                reverse(temp2.begin(), temp2.end());
                if (temp == temp2) {
                    if (temp.size() > ans.size()) {
                        ans = temp;
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
 
    return 0;
 }