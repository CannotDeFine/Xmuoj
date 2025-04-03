/*
 * @Author: cdf
 * @Date: 2024-11-08 23:47:39
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 23:54:54
 * @Description: xmuoj_石头剪子布
 */

#include<bits/stdc++.h>
using namespace std;

string determineWinner(string s1, string s2) {
    if (s1 == s2) {
        return "Tie";
    }
    if ((s1 == "Rock" && s2 == "Scissors") ||
        (s1 == "Scissors" && s2 == "Paper") ||
        (s1 == "Paper" && s2 == "Rock")) {
        return "Player1";
    } else {
        return "Player2";
    }
}

int main() {
    int n;
    cin >> n;
    string s1, s2;
    
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        cout << determineWinner(s1, s2) << endl;
    }
    
    return 0;
}