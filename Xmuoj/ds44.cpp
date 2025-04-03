/*
 * @Author: cdf
 * @Date: 2025-02-27 15:18:44
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-28 21:35:58
 * @Description: 完全二叉树的层序遍历
 */

 // 可能是 oj 上的错误

 #include<bits/stdc++.h>
 using namespace std;
 
 struct node
 {
    int val;
    node* left;
    node* right;
    node(): val(0), left(nullptr), right(nullptr){}
 };

 void Inputpostorder(node* root)
 {
    if (root)
    {
        Inputpostorder(root -> left);
        Inputpostorder(root -> right);
        cin >> root -> val;
    }
 }

 int main()
 {
    int n;
    cin >> n;

    //vector<int> rem(n + 1);
    //for (int i = 1; i <= n; i++) cin >> rem[i];

    int num = 1;
    node* root = new node();
    root -> val = 1;

    // 层序构建树
    queue<node*> que;
    que.push(root);
    while (1)
    {
        node* tmp = que.front();
        que.pop();

        node* l = new node();
        num++;
        l -> val = num;
        tmp -> left = l;
        que.push(l);
        if (num >= n) break;

        node* r = new node();
        num++;
        r -> val = num;
        tmp -> right = r;
        que.push(r);
        if (num >= n) break;

    }
    
    // 后序遍历树， 并且将数据填入树中
    Inputpostorder(root);
    
    // 层序遍历树
    vector<int> ans;
    queue<node*> myque;
    myque.push(root);
    while (!myque.empty())
    {
        node* tmp = myque.front();
        myque.pop();
        ans.push_back(tmp -> val);

        if (tmp -> left)
        {
            myque.push(tmp -> left);
        }
        if (tmp -> right)
        {
            myque.push(tmp -> right);
        }

    }

    // 打印结果
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1) cout << ans[i] ;
        else cout << ans[i] << ' ';
    }

    return 0;
 }
