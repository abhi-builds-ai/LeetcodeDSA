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
void dfs(TreeNode* root, int level, vector<int>&sum)
{
    if(root == NULL)
    return;
    if(level == sum.size())  //if this is the first node we rae seeing at this level, create a new space in the vector for this level's sum
    sum.push_back(0);

    sum[level] += root->val;

    dfs(root->left,level+1,sum);
    dfs(root->right,level+1,sum);

}
    int maxLevelSum(TreeNode* root) {
        vector<int>sum;

        dfs(root,0,sum);

        int maxsum = INT_MIN;
        int ans = 0;

        for(int i =0;i<sum.size();i++)
        { 
            if(sum[i]>maxsum)
            {
            maxsum = sum[i];
            ans = i+1;
            }
        }
        return ans;
    }
};


// BFS Approach
// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         queue<TreeNode*>q;
//         if(root == NULL)
//         return 0;
//         q.push(root);
//         int maxsum =INT_MIN;
//         int ans =0;
//         int level =0;

//         while(!q.empty())
//         {
//             int sum = 0;
//             level++;
//             // TreeNode* curr = q.front();
//             int n = q.size();
//             while(n--)
//             {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 sum += curr->val;
//                 if(curr->left)
//                 q.push(curr->left);
//                 if(curr->right)
//                 q.push(curr->right);

//             }
//             if(sum>maxsum)
//             {
//                 maxsum = sum;
//                 ans = level;
//             }

//         }
//         return ans;
//     }
// };