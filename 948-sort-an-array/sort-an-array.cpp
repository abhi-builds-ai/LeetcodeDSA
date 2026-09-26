class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i =0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        int mini = *min_element(nums.begin(),nums.end()); //o(n)
        int maxi = *max_element(nums.begin(),nums.end()); //o(n)
        
        int j =0;

        for(int i = mini;i<=maxi;i++)  //o(k)
        {
            while(mpp[i]>0)   //o(n)
            {
                nums[j]=i;
                j++;
                mpp[i]--;
            }
        }
        return nums;
    }
};

//tc:o(k+n)