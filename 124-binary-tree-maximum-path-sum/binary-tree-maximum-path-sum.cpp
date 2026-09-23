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

    int maxsum = INT_MIN;

    int find(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        int leftsum = find(root->left);
        int rightsum = find(root->right);

        int dono_shi_hai = leftsum + rightsum + root->val;

        int koi_ek_acha = root->val + max(leftsum,rightsum);

        int dono_bekar = root->val;

        maxsum = max({maxsum,dono_shi_hai,koi_ek_acha,dono_bekar});

        return max(koi_ek_acha, dono_bekar);
    }

    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        find(root);
        return maxsum;

    }
};

// TC:O(N)
//SC:O(H) recursion stack