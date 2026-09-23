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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool LeftToRight = true;
        queue<TreeNode*>q;
        vector<vector<int>>ans;

        if(root == NULL)
        return ans;

        q.push(root);

        while(!q.empty())
        {
            vector<int>temp;

            int n = q.size();
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left)
                q.push(curr->left);

                if(curr->right)
                q.push(curr->right);
            }
            if(!LeftToRight)
            {
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            LeftToRight = !LeftToRight;
        }
        return ans;
    }
};

//tc:o(n)
//sc:o(n)