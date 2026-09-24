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



 /*

 // brute force idea
 // for every node , find the sum of its subtree, find the no of nodes in its subtree, compute average, then check  ,  repeat for every node


class Solution {
public:
    int ans = 0;

    int findsum(TreeNode* root)  // O(n)
    {
        if(root == NULL)
        return 0;

        return root->val + findsum(root->left) + findsum(root->right);
    }

    int findcount(TreeNode* root)  // O(n)
    {
        if(root == NULL)
        return 0;

        return 1 + findcount(root->left)+ findcount(root->right);
    }

    void dfs(TreeNode* root)
    {
        if(root == NULL)
        return;

        int sum = findsum(root);
        int cnt = findcount(root);

        if(sum/cnt == root->val)
        ans++;

        dfs(root->left);
        dfs(root->right);
    }
    int averageOfSubtree(TreeNode* root) {

        dfs(root);
        return ans;

    }
};

// TC : O(n2)
// SC : O(h)

*/


// Optimal code    (Postorder DFS)
class Solution {
public:

    int res;
    pair<int,int>solve(TreeNode* root)       // {sum,cnt}
    {
        if(!root)
        {
            return {0,0};
        }

        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);

        int totalsum = left.first + right.first + root->val;
        int totalcnt = left.second + right.second + 1;

        int avg = totalsum/totalcnt;

        if(avg == root->val)
        res +=1;

        return {totalsum, totalcnt};
    }
    int averageOfSubtree(TreeNode* root) {

        res = 0;

        solve(root);
        return res;
        
    }
};