// User function Template for C++
class Solution {
    void toposort (int node, vector<pair<int, int>> adj[], vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (auto it: adj[node]) {
            int v = it.first;
            if (!visited[v]) {
                toposort (v, adj, visited, st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        
        for (int i = 0; i < E; i++) {
            int v = edges[i][0];
            int u = edges[i][1];
            int wt = edges[i][2];
            
            adj[v].push_back({u, wt});
        }
        
        vector<int> visited(V, 0);
        vector<int> dist(V, 1e9);
        
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                toposort(i, adj, visited, st);
            }
        }
        
        dist[0] = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for (int& i : dist) {
            if (i == 1e9) i = -1;
        }
        
        return dist;
    }
};
