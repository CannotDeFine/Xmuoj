/*
 * @Author: cdf
 * @Date: 2025-03-06 16:56:29
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-06 17:34:59
 * @Description: 德才论
 */

 #include <bits/stdc++.h>
 using namespace std;

 struct node
 {
    string num;
    int de;
    int cai;
 };

 int base_score, first_score; // 最低录取分数线 和 优先录取分数线

 bool cmp(node  a, node  b)
 {
    return (a.de + a. cai > b.de + b.cai) || (a.de + a.cai == b.de + b.cai && a.de > b.de) ||
    (a.de + a.cai == b.de + b.cai && a.de == b.de && a.num < b.num);
 }

 int main()
 {
    int n;
    cin >> n;

    cin >> base_score >> first_score;

    vector<node> stu(n);
    vector<node> ans1;
    vector<node> ans2;
    vector<node> ans3;
    vector<node> ans4;
    for (int i = 0; i < n; i++)
    {
        string nu;
        int de, cai;
        cin >> nu;
        cin >> de >> cai;
        // cout << nu << endl;
        // cout << de  << ' ' << cai << endl;

        stu[i].num = nu;
        stu[i].de = de;
        stu[i].cai = cai;

        if (de >= first_score && cai >= first_score) ans1.push_back(stu[i]);
        else if (de >= first_score && cai < first_score && cai >= base_score) ans2.push_back(stu[i]);
        else if (de < first_score && de >= base_score && cai < first_score && cai >= base_score && de >= cai) ans3.push_back(stu[i]);
        else if (de >= base_score && cai >= base_score) ans4.push_back(stu[i]);
        else continue;
    }

    sort (ans1.begin(), ans1.end(), cmp);
    sort (ans2.begin(), ans2.end(), cmp);
    sort (ans3.begin(), ans3.end(), cmp);
    sort (ans4.begin(), ans4.end(), cmp);

    cout << ans1.size() + ans2.size() + ans3.size() + ans4.size() << endl;
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i].num << ' ' << ans1[i].de << ' ' << ans1[i].cai << endl;
    }
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i].num << ' ' << ans2[i].de << ' ' << ans2[i].cai << endl;
    }
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i].num << ' ' << ans3[i].de << ' ' << ans3[i].cai << endl;
    }
    for (int i = 0; i < ans4.size(); i++)
    {
        cout << ans4[i].num << ' ' << ans4[i].de << ' ' << ans4[i].cai << endl;
    }

    return 0;
 }