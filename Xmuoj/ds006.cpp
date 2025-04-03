/*
 * @Author: cdf
 * @Date: 2025-02-27 11:00:22
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-27 11:21:01
 * @Description: 二叉树的遍历
 */

 #include<bits/stdc++.h>
 using namespace std;

 struct Node
 {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr){};
 };

 Node* buildtree(vector<int> inorder, vector<int> postorder, int insta, int inend, int poststa, int postend)
 {
    if (insta > inend) return nullptr;

    int rootval = postorder[postend];
    Node* t = new Node(rootval);

    int rootidx;
    while (inorder[rootidx] != rootval)
    {
        rootidx ++;
    }

    int leftsize = rootidx - insta;
    t -> left = buildtree(inorder, postorder, insta, rootidx - 1, poststa, poststa + leftsize - 1);
    t -> right = buildtree(inorder, postorder, rootidx + 1, inend, poststa + leftsize, postend - 1);

    return t;
 }

 int main()
 {
    int n;
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    Node* t = buildtree(inorder, postorder, 0, n - 1, 0, n - 1);

    queue<Node*> sta;
    vector<int> ans;
    sta.push(t);
    while (!sta.empty())
    {
        Node* tmp = sta.front();
        sta.pop();
        ans.push_back(tmp -> val);

        if (tmp -> left) sta.push(tmp -> left);
        if (tmp -> right) sta.push(tmp -> right);
    }

    for (int i = 0; i < ans.size() ; i++)
    {
        if (i == ans.size() - 1) cout << ans[i];
        else cout << ans[i] << ' ';
    }

    return 0;

 }