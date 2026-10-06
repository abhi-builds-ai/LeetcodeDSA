
//DFS Code

class Solution {
public:

    bool hascycle;

    void dfs(unordered_map<int,vector<int>>&adj,int u, vector<bool>&visited,stack<int>&st,vector<int>&inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u])
        {
            if(inRecursion[v] == true)
            {
                hascycle = true;
                return;
            }

            if(!visited[v])
            {
                dfs(adj,v,visited,st,inRecursion);
            }
        }

        inRecursion[u] = false;
        st.push(u);
    }

    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>>adj;

        vector<int>inRecursion(numCourses,false);
        vector<bool>visited(numCourses,false);
        hascycle = false;

        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

        }

        stack<int>st;

        for(int i =0;i<numCourses;i++)
        {
            if(!visited[i])
            dfs(adj,i,visited,st,inRecursion);
        }

        if(hascycle == true)
        return {};

        vector<int>res;

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;


    }
};




// class Solution {
// public:

//     void toposort(unordered_map<int,vector<int>>&adj,int n,vector<int>&res,vector<int>&indegree)
//     {
//         queue<int>q;

//         for(int i =0;i<n;i++)
//         {
//             if(indegree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }

//         while(!q.empty())
//         {
//             int x =q.front();
//             res.push_back(x);
//             q.pop();

//             for(int &v : adj[x])
//             {
//                 indegree[v]--;

//                 if(indegree[v] == 0)
//                 q.push(v);
//             }

//         }

        
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>>adj;
//         vector<int>res;

//         vector<int>indegree(numCourses,0);

//         for(auto &vec : prerequisites)
//         {
//             int a = vec[0];
//             int b = vec[1];

//             adj[b].push_back(a);

//             indegree[a]++;
//         }

//         toposort(adj,numCourses,res,indegree);

//         return res;
//     }
// };

