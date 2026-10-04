/*
//Approach-1 : [ Using DFS - Creating our own Map as graph ]
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours
        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        
        return count;
        
    }
};
*/

/*
//Approach-2 : [ Using DFS - Using given input graph]
class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        
        return count;
        
    }
};

*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        queue<int> q;
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            provinces++;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (isConnected[node][j] == 1 && !vis[j]) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }
        }

        return provinces;
    }
};

// TC: O(n2) we are traversing entire adj matrix
// SC : O(n)