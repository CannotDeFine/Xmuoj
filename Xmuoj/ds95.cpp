/*
 * @Author: cdf
 * @Date: 2025-03-07 13:19:23
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 13:55:45
 * @Description: PTA排名汇总
 */

 #include <bits/stdc++.h>
 using namespace std;

 // to remember the info of the stu
 struct node
 {
    string num;
    int score;
    int point;
    int point_rank;
    int total_rank;
 };

 bool cmp(node a, node b)
 {
    return (a.score > b.score) || (a.score == b.score && a.num < b.num);
 }
 
 // to calculate the point rank
 void calculate_point_rank(vector<node> &temp)
 {
    int pre_score = temp[0].score;
    int pre_rank = 1;
    int i = 0;
    while (i < temp.size())
    {
        if (temp[i].score == pre_score)
        {
            temp[i].point_rank = pre_rank;
        }
        else
        {
            temp[i].point_rank = i + 1;
            pre_rank = i + 1;
            pre_score = temp[i].score;            
        }

        i++;
    }
 }

 // to calculate the total rank
 void calculate_total_rank(vector<node> &temp)
 {
    int pre_score = temp[0].score;
    int pre_rank = 1;
    int i = 0;
    while (i < temp.size())
    {
        if (temp[i].score == pre_score)
        {
            temp[i].total_rank = pre_rank;
        }
        else
        {
            temp[i].total_rank = i + 1;
            pre_rank = i + 1;
            pre_score = temp[i].score;            
        }

        i++;
    }
 }

 int main()
 {
    int point_num;
    cin >> point_num;

    int totalStuNum = 0;
    vector<node> total_stu;
    for (int i = 1; i <= point_num; i++)
    {
        int temp;
        cin >> temp;
        totalStuNum += temp;                // count the num of people

        // input the info of student of this point
        vector<node> temp_stu(temp);
        for (int j = 0; j < temp; j++)
        {
            cin >> temp_stu[j].num >> temp_stu[j].score;
            temp_stu[j].point = i;
        }

        // sort besed  on the score
        sort(temp_stu.begin(), temp_stu.end(),cmp);
        calculate_point_rank(temp_stu);
        //stu.push_back(temp_stu);

        // put the info into the total table
        for (int j = 0; j < temp_stu.size(); j++)
        {
            total_stu.push_back(temp_stu[j]);
        }
        
    }

    // calculate the total rank
    sort (total_stu.begin(), total_stu.end(), cmp);
    calculate_total_rank(total_stu);

    // output the answer
    cout << total_stu.size() << endl;
    for (int i = 0; i < total_stu.size(); i++)
    {
        cout << total_stu[i].num << ' ' << total_stu[i].total_rank << ' ' << total_stu[i].point << ' ' << total_stu[i].point_rank << endl; 
    }

    return 0;
 }