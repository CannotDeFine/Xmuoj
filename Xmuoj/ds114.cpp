/*
 * @Author: cdf
 * @Date: 2025-02-20 22:14:41
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-20 22:35:23
 * @Description: 三元组顺序表表示的稀疏矩阵转置运算
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 const int N = 100;

 typedef struct {
    int r;
    int c;
    int val;
 }Triple;

 typedef struct{
    Triple  data[N];
    int rownum;
    int colnum;
    int valnum;
 }TSMatix;

 bool cmp(Triple a, Triple b)
 {
    return a.r < b.r || (a.r == b.r && a.c < b.c);
 }

 void TransposeMatrix(TSMatix a, TSMatix & b)
 {
    b.rownum = a.rownum;
    b.colnum = a.colnum;
    b.valnum = a.valnum;

    if (b.valnum)
    {
        int k = 0;
        for (int i = 0; i < a.colnum; i++)
        {
            for (int j = 0; j < a.valnum; j++)
            {
                if (a.data[j].c == i)
                {
                    b.data[k].r = a.data[j].c;
                    b.data[k].c = a.data[j].r;
                    b.data[k].val = a.data[j].val;

                    k++;
                }
            }
        }
    }
 }
 
 int main() {
 
    int row, col, num;
    cin >> row >> col >> num;

    TSMatix a;
    a.rownum = row;
    a.colnum = col;
    a.valnum = num;

    int k = 0;
    while (num--)
    {
        int r, c, val;
        cin >> r >> c >> val;

        a.data[k].c = c;
        a.data[k].r = r;
        a.data[k].val = val;

        k++;
    }

    TSMatix b;

    //TransposeMatrix(TSMatix a, TSMatix &b);
    b.rownum = a.rownum;
    b.colnum = a.colnum;
    b.valnum = a.valnum;

    if (b.valnum)
    {
        int k = 0;
        for (int i = 0; i < a.colnum; i++)
        {
            for (int j = 0; j < a.valnum; j++)
            {
                if (a.data[j].c == i)
                {
                    b.data[k].r = a.data[j].c;
                    b.data[k].c = a.data[j].r;
                    b.data[k].val = a.data[j].val;

                    k++;
                }
            }
        }
    }
    sort (b.data , b.data + b.valnum, cmp);

    for (int i = 0; i < b.valnum; i++)
    {
        cout << b.data[i].r << ' ' << b.data[i].c << ' ' << b.data[i].val <<  endl; 
    }

    return 0;
 }
