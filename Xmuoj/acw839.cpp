/*
 * @Author: cdf
 * @Date: 2025-03-14 21:01:39
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 21:42:51
 * @Description: 模拟堆
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;
 int heap[N], ptoh[N], htop[N];
 int heap_size = 0, idx_size = 0;

 void heap_swap(int a, int b)
 {
    swap(ptoh[htop[a]], ptoh[htop[b]]);
    swap(htop[a], htop[b]);
    swap(heap[a], heap[b]);
 }

 void down(int u)
 {
    int t = u;
    if (2 * u <= heap_size && heap[2 * u] <= heap[t]) t = 2 * u;
    if (2 * u + 1 <= heap_size && heap[2 * u + 1] <= heap[t]) t = 2 * u + 1;

    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }  
 }

 void up (int u)
 {
    while (u / 2 && heap[u] < heap[u / 2])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
 }

 int main()
 {
    int n;
    cin >> n;

    while (n--)
    {
        string op;
        cin >> op;

        if (op == "I")
        {
            int num;
            cin >> num;

            heap_size++;
            idx_size++;

            ptoh[idx_size] = heap_size;
            htop[heap_size] = idx_size;
            heap[heap_size] = num;
            up(heap_size);
        }
        else if (op == "PM")
        {
            cout << heap[1] << endl;
        }
        else if (op == "DM")
        {
            heap_swap(1, heap_size);
            heap_size--;
            down(1);
        }
        else if (op == "D")
        {
            int k;
            cin >> k;

            // 获取在 heap 中的下标 u
            int u = ptoh[k];
            // 将删除位置交换到末尾
            heap_swap(u, heap_size);
            // 数量减少 1
            heap_size--;

            // 对堆进行向上向下调整
            down(u);
            up(u);
        }
        else 
        {
            int k, num;
            cin >> k >> num;

            int u = ptoh[k];
            heap[u] = num;

            down(u);
            up(u);
        }
    }

    return 0;

 }
