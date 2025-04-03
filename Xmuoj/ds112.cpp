/*
 * @Author: cdf
 * @Date: 2025-02-17 23:40:37
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-20 21:50:03
 * @Description: 稀疏矩阵加法（支持覆盖相同单元）
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 // 三元组结构体
 typedef struct {
     int r;
     int c;
     int val;
 } Triple;
 
 // 稀疏矩阵结构体
 typedef struct {
     Triple *data; // 三元组数组
     int row, col; // 矩阵行数、列数
     int num;      // 非零元素个数
 } TSMatrix;
 
 // 排序比较函数：按行排序，若行相同，则按列排序
 bool cmp(Triple a, Triple b) {
     return (a.r < b.r) || (a.r == b.r && a.c < b.c);
 }
 
 // 读取矩阵（去重处理相同位置）
 void readMatrix(TSMatrix &M, int r, int c) {
     unordered_map<int, int> valueMap; // 记录 (r, c) -> val
     int num;
     cin >> num;
 
     for (int i = 0; i < num; i++) {
         int row, col, val;
         cin >> row >> col >> val;
         valueMap[row * 10000 + col] = val; // 覆盖旧值
     }
 
     // 转换为三元组数组
     M.row = r;
     M.col = c;
     M.num = valueMap.size();
     M.data = (Triple *)malloc(sizeof(Triple) * M.num);
     
     int index = 0;
     for (auto &it : valueMap) {
         M.data[index].r = it.first / 10000;
         M.data[index].c = it.first % 10000;
         M.data[index].val = it.second;
         index++;
     }
 
     // 按 (r, c) 排序
     sort(M.data, M.data + M.num, cmp);
 }
 
 int main() {
     int r, c;
     cin >> r >> c;
 
     // 读取矩阵 A
     TSMatrix A;
     readMatrix(A, r, c);
 
     // 读取矩阵 B
     cin >> r >> c;
     
     TSMatrix B;
     readMatrix(B, r, c);
   
     if (A.col != B.col || A.row != B.row)
     {
         cout << "ERROR" << endl;
         return 0;
     }

     // 结果矩阵 C
     TSMatrix C;
     C.row = r;
     C.col = c;
     C.num = 0;
     C.data = (Triple *)malloc(sizeof(Triple) * (A.num + B.num));
 
     int i = 0, j = 0, k = 0;
     while (i < A.num && j < B.num) {
         if (A.data[i].r < B.data[j].r || (A.data[i].r == B.data[j].r && A.data[i].c < B.data[j].c)) {
             C.data[k++] = A.data[i++];
             C.num++;
         } else if (A.data[i].r > B.data[j].r || (A.data[i].r == B.data[j].r && A.data[i].c > B.data[j].c)) {
             C.data[k++] = B.data[j++];
             C.num++;
         } else {
             // 相同位置，相加
             int sum = A.data[i].val + B.data[j].val;
             if (sum != 0) {
                 C.data[k].r = A.data[i].r;
                 C.data[k].c = A.data[i].c;
                 C.data[k].val = sum;
                 C.num++;
                 k++;
             }
             i++;
             j++;
         }
     }
 
     // 处理剩余元素
     while (i < A.num) {
         C.data[k++] = A.data[i++];
         C.num++;
     }
     while (j < B.num) {
         C.data[k++] = B.data[j++];
         C.num++;
     }
 
     // 输出结果
     //cout << C.num << endl;
     for (int i = 0; i < C.num; i++) {
         cout << C.data[i].r << ' ' << C.data[i].c << ' ' << C.data[i].val << endl;
    
     }
     return 0;
} 