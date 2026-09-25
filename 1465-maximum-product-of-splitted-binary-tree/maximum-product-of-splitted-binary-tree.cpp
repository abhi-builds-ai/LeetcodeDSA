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
    long sum = 0;  // total sum of the tree
    long maxprod = 0;

    int find(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        int leftsum = find(root->left);
        int rightsum = find(root->right);

        long subtreesum = root->val + leftsum + rightsum;

        long remainingsubtreesum = sum - subtreesum;
        
        long product =  subtreesum * remainingsubtreesum;
        maxprod = max(maxprod,product);

        return subtreesum;



    }

    int totalsum(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        int leftsubtreesum = totalsum(root->left);
        int rightsubtreesum = totalsum(root->right);
        int sum = root->val + leftsubtreesum + rightsubtreesum;

        return sum;

    }

   
    int maxProduct(TreeNode* root) {
        
        if(!root)
        return 0;

        maxprod =0;
        sum = totalsum(root);
        find(root);

        int m = 1000000007;

        return maxprod%m;

    }
};