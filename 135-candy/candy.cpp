class Solution {
public:// SC: O(n)
    int candy(vector<int>& rating) {
        
    int n = rating.size();

    vector<int>count(n,1);


    for(int i =1;i<n;i++)
    {
        if(rating[i]>rating[i-1])
        {
            count[i] = max(count[i],count[i-1]+1);
        }
    }
    for(int i =n-2;i>=0;i--)
    {
        if(rating[i]>rating[i+1])
        {
            count[i] = max(count[i],count[i+1]+1);
        }
    }
    int res =0;
    for(int i =0;i<n;i++)
    {
        res+= count[i];
    }
    return res;
    }
};


/*

class Solution {
public:// SC: O(2n)
    int candy(vector<int>& rating) {
        
    int n = rating.size();

    vector<int>L2R(n,1);
    vector<int>R2L(n,1);

    for(int i =1;i<n;i++)
    {
        if(rating[i]>rating[i-1])
        {
            L2R[i] = max(L2R[i],L2R[i-1]+1);
        }
    }
    for(int i =n-2;i>=0;i--)
    {
        if(rating[i]>rating[i+1])
        {
            R2L[i] = max(R2L[i],R2L[i+1]+1);
        }
    }
    int res =0;
    for(int i =0;i<n;i++)
    {
        res+= max(R2L[i],L2R[i]);
    }
    return res;
    }
};

*/