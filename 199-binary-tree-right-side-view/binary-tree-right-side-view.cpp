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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        if(root == NULL)
        return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            ans.push_back(q.back()->val);
            int n = q.size();

            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                q.push(curr->left);

                if(curr->right)
                q.push(curr->right);
            }

        }
        return ans;
    }
};

// Recursive code
// class Solution {
// public:

//     void find(TreeNode * root,int level,vector<int>&ans)
//     {
//         if(root == NULL)
//         return;

//         if(level>ans.size())
//         ans.push_back(root->val);

//         find(root->right,level+1,ans);
//         find(root->left,level+1,ans);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>ans;
//         int level=1;
//         find(root,level,ans);
//         return ans;
        
//     }
// };