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

// DFS Approach

class Solution {
public:
vector<int>result;

     void dfs(TreeNode * root, int depth)
     {
        if(root == NULL)
        return;

        if(depth == result.size())
        {
            result.push_back(root->val);
        }
        else
        {
            result[depth] = max(result[depth],root->val);
        }

        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
     }
    vector<int> largestValues(TreeNode* root) {
        
        dfs(root,0); // root,depth
        return result;



    }
};

/*
// BFS

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int>ans;

        if(root == NULL)
        return ans;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;

            while(n--)
            {
                TreeNode *node = q.front();
                q.pop();

                maxi = max(maxi,node->val);
                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);
            }

                ans.push_back(maxi);
            
        }

        return ans;
        
    }
};
*/