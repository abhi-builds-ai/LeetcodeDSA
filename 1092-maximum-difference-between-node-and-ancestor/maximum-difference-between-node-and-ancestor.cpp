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

    int findMaxDiff(TreeNode* root,int minv, int maxv)
    {
        if(root == NULL)
        return abs(minv-maxv);

        minv = min(minv,root->val);
        maxv = max(maxv,root->val);

        int l  = findMaxDiff(root->left,minv,maxv);
        int r = findMaxDiff(root->right,minv,maxv);

        return max(l,r);
    }

    int maxAncestorDiff(TreeNode* root) {

        return findMaxDiff(root,root->val,root->val);
        
    }
};


// Brute approach
// class Solution {
// public:
//     int ans = 0;
//     void dfs(TreeNode* root, vector<int>&path)
//     {
//         if(root == NULL)
//         return;

//         //compare current node with all ancestors
//         for(int i =0;i<path.size();i++)
//         {
//             ans = max(ans,abs(root->val-path[i]));
//         }

//         path.push_back(root->val);

//         dfs(root->left,path);
//         dfs(root->right,path);

//         path.pop_back();
//     }

//     int maxAncestorDiff(TreeNode* root) {

//         vector<int>path;

//         dfs(root,path);

//         return ans;
        
//     }
// };
// //TC:O(n)2 in worst case