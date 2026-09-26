class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i =0;
        while(i<n/2)
        {
            swap(s[i],s[n-i-1]);
            i++;
        }
        
    }
};

// class Solution {
// public:
    
//     void rev(vector<char>&s,int i,int j)
//     {
//         if(i>=j)
//         return;

//         swap(s[i],s[j]);

//         rev(s,i+1,j-1);
//     }
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         rev(s,0,n-1);
        
//     }
// };