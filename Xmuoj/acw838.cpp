/*
 * @Author: cdf
 * @Date: 2025-03-14 15:37:06
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 15:48:38
 * @Description: 堆排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;
 int heap[N];
 int heap_size = 0;

  void down(int u)
  {
    int t = u;
    if (2 * u <= heap_size && heap[2 * u] <= heap[t]) t = 2 * u;
    if (2 * u + 1 <= heap_size && heap[2 * u + 1] <= heap[t]) t = 2 * u + 1;

    if (t != u)
    {
        swap(heap[t], heap[u]);
        down(t);
    }
  }

 int main()
 {
    int n, m;
    cin >> n >> m;
    heap_size = n;

    for (int i = 1; i <= n; i++) cin >> heap[i];

    // 构建小根堆
    for (int i = heap_size / 2; i > 0; i--) down(i);

    // 每次取堆顶元素，并且对堆进行调整
    while (m--)
    {
        cout << heap[1] << ' ';
        heap[1] = heap[heap_size];
        heap_size--;
        down(1);
    }

    return 0;
 }
