class Solution {
public:
    void solve(int start, vector<int>& nums,
               vector<int>& temp, vector<vector<int>>& ans) {

        // Every subsequence of length >= 2 is an answer
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {

            // Avoid duplicate subsequences at this level
            if (used.count(nums[i]))
                continue;

            // Must be non-decreasing
            if (!temp.empty() && nums[i] < temp.back())
                continue;

            used.insert(nums[i]);

            // Choose
            temp.push_back(nums[i]);

            // Explore
            solve(i + 1, nums, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};


// tc: n.2^n  n for copying valid res into ans and 2^n no of possible subsequences
// sc:O(N)