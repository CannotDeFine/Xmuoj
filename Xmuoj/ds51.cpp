/*
 * @Author: cdf
 * @Date: 2025-02-28 15:27:35
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-28 16:32:05
 * @Description: 修理牧场：关于最小堆和哈夫曼树的应用
 */

 #include <bits/stdc++.h>
 using namespace std;

 typedef struct node * Bitree;
 typedef struct heap * Heap;

 struct node
 {
    int data;
    struct node * left;
    struct node * right;
 };

 struct heap
 {
    Bitree * d;  // 表示关于n个结点数组
    int size;
 };
 
 Heap Insert(Heap h, Bitree b); // insert the element to the min heap
 Bitree Delete(Heap h);         // delete the min element from the min heap
 Bitree Create(Heap H);         // 创建哈夫曼树
 void Sum(Bitree b);            // 记录结果

 int sum = 0;

 int main()
 {
    int n;
    cin >> n;

    Bitree b;
    Heap h;
    h = (Heap)malloc(sizeof(struct heap));
    h -> d = (Bitree *) malloc ((n + 1) * sizeof(Bitree));

    // 初始化堆
    for (int i = 0; i <= n; i++)
    {
        h->d[i] = (Bitree)malloc(sizeof(struct node));
    }
    h -> d[0] -> data = -100;
    h -> d[0] -> left = nullptr;
    h -> d[0] -> right = nullptr;
    h -> size = 0;

    // 构建堆
    for (int i = 1; i <= n; i++)
    {
        b = (Bitree) malloc (sizeof(struct node));
        cin >> b -> data;
        b -> left = nullptr;
        b -> right = nullptr;

        h = Insert(h, b);
    }

    Bitree hf;
    hf = Create(h);
    Sum(hf);

    cout << sum << endl;
    return 0;

 }

 Heap Insert(Heap h, Bitree b)
 {
    int i = ++ h -> size;
    // 实际上是一个元素下移的过程
    while (b -> data < h -> d[i / 2] -> data)
    {
        h -> d[i] = h -> d[i / 2];
        i = i / 2;
    }
    // 将元素插入当前位置
    h -> d[i] = b;
    return h;
 }

 // 对最小堆进行删除和调整
 Bitree Delete (Heap h)
 {
    Bitree b;
    b = h -> d[1];

    int i = h -> size;
    int j = 2;      // 从第二个结点进行比较
    while (j < i)
    {
        // 选择较小的兄弟结点
        if (h -> d[j] -> data > h-> d[j + 1] -> data)
        {
            j = j + 1;
        }
        // 结点上移的过程
        if (h -> d[j] -> data < h -> d[i] -> data)
        {
            h -> d[j / 2] = h -> d[j]; 
        }
        else break;
        // 向下比较
        j = j * 2; 
    }

    h -> d[j / 2] = h -> d[i];
    h -> size --;
    
    return b;
 }

 // 构建哈弗曼树
 Bitree Create(Heap h)
 {
    Bitree p1, p2, p;
    while (h -> size != 1)  // 直到堆内剩一个最小元素
    {
        // 得到两个最小结点
        p = (Bitree) malloc (sizeof(struct node));
        p1 = Delete (h);
        p2 = Delete (h);

        // 新建结点并且合并的过程
        p -> data = p1 -> data + p2 -> data;
        p -> left = p1;
        p -> right = p2;
        h = Insert (h, p);
    }

    return h -> d[h -> size];
 }

 void Sum(Bitree b)
 {
    if (b != nullptr)
    {
        if (b -> left != nullptr && b -> right != nullptr) sum = sum + b -> data;
        Sum (b -> left);
        Sum (b -> right);
    }
 }