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
 // BFS Approach
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);

        bool even_level = true;

        while(!q.empty())
        {
            int n = q.size();

            int prev;
            if(even_level)
            prev = INT_MIN;
            else
            prev = INT_MAX;

            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(even_level && (curr->val%2 == 0 || curr->val<= prev))
                {
                    return false;
                }

                if(!even_level && (curr->val%2 != 0 || curr->val>= prev))
                {
                    return false;
                }


                prev = curr->val;
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);

            }
            even_level = !even_level;
        }


        return true;
        
    }
};
// TC: O(N)
// SC: O(N)
*/

// DFS

class Solution {
public:
    
    vector<int> levelPrev;
    
    bool solve(TreeNode* root, int level) {
        if(!root) {
            return true;
        }
        
        if((level%2 == 0 && root->val%2 == 0) || (level%2 != 0 && root->val%2 != 0)) {
            return false;
        }
        
        if(level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0) { //already there is a value at this level
            if((level%2 == 0 && root->val <= levelPrev[level]) ||
               (level%2 != 0 && root->val >= levelPrev[level]))
                return false;
        }
        
        levelPrev[level] = root->val;
        
        return solve(root->left, level+1) && solve(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};