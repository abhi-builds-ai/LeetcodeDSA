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

// Approach : Graph + BFS
class Solution {
public:

    void makegraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*,vector<TreeNode*>>&adj,unordered_set<TreeNode*>&st)
    {

        if(root == NULL)
        return;

        if(root->left == NULL && root->right == NULL)
        st.insert(root);

        if(prev != NULL)
        {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makegraph(root->left,root,adj,st);
        makegraph(root->right,root,adj,st);

    }
    int countPairs(TreeNode* root, int distance) {

        unordered_map<TreeNode*, vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;

        makegraph(root,NULL,adj,st);

        int count = 0;

        for(auto &leaf : st)
        {
            //BFS hit karo aur dekho can u find another leaf nodes within distance
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int level = 0;level<=distance;level++)
            {
                int size = q.size();
                while(size--)
                {
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr!=leaf && st.count(curr))
                    count++;

                    for(auto &ngbr : adj[curr])
                    {
                        if(!visited.count(ngbr))
                        {
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }

        return count/2;
    }
};