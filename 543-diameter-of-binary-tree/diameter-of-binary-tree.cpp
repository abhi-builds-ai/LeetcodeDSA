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
    int diameter = 0;

    int find(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        int l = find(root->left);
        int r = find(root->right);

        diameter = max(diameter, r+l);

        return 1 + max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        diameter = 0;
        find(root);

        return diameter;
        


        
    }
};

// TC : O(N)