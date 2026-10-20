class Solution {
public:
    int getdigitssum(int num)
    {
        int sum = 0;

        while(num > 0)
        {
            sum += (num%10);
            num /=10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int>aftersorted(nums);

        auto lambda = [&](int num1, int num2)         // custom sort
        {
            int num1digitsum = getdigitssum(num1);
            int num2digitsum = getdigitssum(num2);

            if(num1digitsum != num2digitsum)
            {
                return num1digitsum < num2digitsum;
            }

            return num1 < num2;
        };
        sort(aftersorted.begin(), aftersorted.end(), lambda);

        unordered_map<int,int>valtoidx;

        for(int i =0;i<n;i++)
        {
            valtoidx[nums[i]] = i;
        }

        int swapcnt = 0;

        for(int i =0;i<n;i++)
        {
            int expectedval = aftersorted[i];
            int currval = nums[i];

            if(expectedval == currval)
            continue;

            int idx = valtoidx[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;

            valtoidx[expectedval] = i;
            valtoidx[currval] = idx;

            swapcnt++;
        }


        return swapcnt;
        
    }
};


// Yha ham custom sort use kar rhe hai