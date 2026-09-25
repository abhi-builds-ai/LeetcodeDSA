/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* left, TreeNode* right, int level)
    {
        if(left == NULL || right == NULL)
        return;

        if(level%2 == 1)
        swap(left->val,right->val);

        solve(left->left,right->right,level+1);
        solve(left->right,right->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL)
        return root;

        solve(root->left,root->right,1);

        return root;
    }
};



// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {

//         if (root == NULL)
//             return root;

//         queue<TreeNode*> q;
//         q.push(root);

//         int level = 0;

//         while (!q.empty()) {

//             int n = q.size();
//             vector<TreeNode*> nodes;

//             while (n--) {
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 nodes.push_back(curr);

//                 if (curr->left)
//                     q.push(curr->left);

//                 if (curr->right)
//                     q.push(curr->right);
//             }

//             // Odd level
//             if (level % 2 == 1) {

//                 int i = 0;
//                 int j = nodes.size() - 1;

//                 while (i < j) {
//                     swap(nodes[i]->val, nodes[j]->val);
//                     i++;
//                     j--;
//                 }
//             }

//             level++;
//         }

//         return root;
//     }
// };