/*
 * @Author: cdf
 * @Date: 2025-02-26 22:01:14
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-27 10:58:57
 * @Description: 根据中序和后序序列输出前序序列
 */


 #include <iostream>
 #include <vector>
 using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     // 构造函数
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 // 根据中序和后序遍历构造二叉树
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
     if (inStart > inEnd) return nullptr;
     
     int rootVal = postorder[postEnd];
     TreeNode* root = new TreeNode(rootVal);
     
     int rootIndex = inStart;
     while (inorder[rootIndex] != rootVal) rootIndex++;
     
     int leftSize = rootIndex - inStart;
     root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
     root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
     
     return root;
 }
 
 // 先序遍历
 void preorderTraversal(TreeNode* root, vector<int>& result) {
     if (!root) return;
     result.push_back(root->val);
     preorderTraversal(root->left, result);
     preorderTraversal(root->right, result);
 }
 
 int main() {
     int N;
     cin >> N;
     vector<int> inorder(N), postorder(N);
     for (int i = 0; i < N; i++) cin >> postorder[i];
     for (int i = 0; i < N; i++) cin >> inorder[i];
     
     TreeNode* root = buildTree(inorder, postorder, 0, N - 1, 0, N - 1);
     
     vector<int> preorder;
     preorderTraversal(root, preorder);
     
     cout << "Preorder:";
     for (int i = 0; i < preorder.size(); i++) {
         cout << " " << preorder[i];
     }
     cout << endl;
     
     return 0;
 }
 