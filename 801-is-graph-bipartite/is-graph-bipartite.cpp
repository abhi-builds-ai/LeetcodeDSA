class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n,-1);

        for(int i =0;i<n;i++)
        {
            //start BFS for every disconnected component
            if(color[i] == -1)
            {
                queue<int>q;

                color[i] = 0;
                q.push(i);

                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    for(int v : graph[u])
                    {
                        if(color[v] == -1)
                        {
                            color[v] = 1- color[u];

                            q.push(v);
                        }
                        else if(color[v] == color[u])
                        {
                            return false;
                        }
                        }
                    }
                }
            }
        return true;
    }
};


// DFS Code

// class Solution {
// public:

//     bool bipartite(vector<vector<int>>& graph,int curr,vector<int>&color,int currcolor)
//     {
//         color[curr] = currcolor;

//         for(int &v : graph[curr])
//         {
//             if(color[v] == color[curr])
//             return false;

//             if(color[v] == -1)
//             {
//                 // never visited
//                 int colorOfV = 1- currcolor;
//                 if(bipartite(graph,v,color,colorOfV) == false)
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int>color(n,-1);

//         for(int i =0;i<n;i++)
//         {
//             if(color[i] == -1)
//             {
//                 if(bipartite(graph,i,color,1) == false)
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// TC : O(V+E)