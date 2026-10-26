class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
        int  i =0;
        vector<vector<int>>res;
        int n = interval.size();
        while(i<n)
        {

            if(interval[i][1] < newinterval[0])
            res.push_back(interval[i]);

            else if(interval[i][0] > newinterval[1])
            {
                break;
            }
            else
            {
                //merge karo
                newinterval[0] = min(newinterval[0], interval[i][0]);
                newinterval[1] = max(newinterval[1], interval[i][1]);
            }
            i++;
        }
        res.push_back(newinterval);
        while(i<n)
        {
            res.push_back(interval[i]);
            i++;
        }
        return res;
    }
};
//TC: O(n)