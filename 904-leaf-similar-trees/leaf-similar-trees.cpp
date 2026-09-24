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
    void find(TreeNode* root,vector<int>&s)
    {
       if(root == NULL)
       return;


       find(root->left,s);
       find(root->right,s);

       if(root->left == NULL && root->right == NULL)
       s.push_back(root->val);
       return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>s1,s2;
        find(root1,s1);
        find(root2,s2);
        return s1== s2;
    }
};
//tc:o(n+m)
//sc:o(n+m)