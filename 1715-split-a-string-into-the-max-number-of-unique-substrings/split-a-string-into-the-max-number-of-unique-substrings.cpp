class Solution {
public:
    
    int ans =0;

    void solve(int start,string &s,unordered_set<string>&st)
    {
       if(start == s.size())
       {
        ans = max(ans,(int)st.size());
        return;
       }

       for(int i = start;i<s.size();i++)
       {
        string part = s.substr(start,i-start+1);

        //already used
        if(st.count(part))
        continue;

        //choose
        st.insert(part);

        solve(i+1,s,st);

        //backtrack
        st.erase(part);
       }
    }
    int maxUniqueSplit(string s) {
        ans =0;
        unordered_set<string>st;
        solve(0,s,st);
        return ans;
        
    }
};