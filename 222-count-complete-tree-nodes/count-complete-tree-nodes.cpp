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

    int getleftheight(TreeNode* root)
    {
        TreeNode* temp = root;
        int lh =0;

        while(temp)
        {
            temp = temp->left;
            lh++;
        }
        return lh;
    }

    int getrightheight(TreeNode* root)
    {
        TreeNode* temp = root;
        int lh =0;

        while(temp)
        {
            temp = temp->right;
            lh++;
        }
        return lh;
    }

    int countNodes(TreeNode* root) {
        
        if(root == NULL)
        return 0;

        int lh = getleftheight(root);
        int rh = getrightheight(root);

        if(lh==rh)  //perfect binary tree
        return pow(2,lh)-1;

        return countNodes(root->left) + countNodes(root->right) + 1;

    }
};

//TC:O(logn)2
// because we are traversing for h, h-1, h-2,...
//O(h)2