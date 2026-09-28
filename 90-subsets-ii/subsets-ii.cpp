class Solution {
public:

    void findsubsets(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int i = index;i<nums.size();i++)
        {
            if(i!=index && nums[i] == nums[i-1])
            continue;

            ds.push_back(nums[i]);

            findsubsets(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findsubsets(0,nums,ds,ans);
        return ans;
        
    }
};

//tc:2^nxn  n for copying subset that we are generating, 2^n for recursion
//sc: 2^nx(k)  2^n subsets and k avg length

// class Solution {
// public:
//     void solve(int index, vector<int>& nums,
//                vector<int>& temp, set<vector<int>>& st) {

//         if(index == nums.size()) {
//             st.insert(temp);
//             return;
//         }

//         // Include
//         temp.push_back(nums[index]);
//         solve(index + 1, nums, temp, st);
//         temp.pop_back();

//         // Exclude
//         solve(index + 1, nums, temp, st);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//         set<vector<int>> st;
//         vector<int> temp;

//         solve(0, nums, temp, st);

//         vector<vector<int>> ans;

//         for(auto x : st) {
//             ans.push_back(x);
//         }

//         return ans;
//     }
// };