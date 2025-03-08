//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int> visited) {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (! q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for (auto& nbr : adj[node]) {
                if (! visited[nbr]) {
                    visited[nbr] = 1;
                    q.push({nbr, node});
                } else if (nbr != par) return true;
            }
        }
        
        
        return false;
    }
    
  public:
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (! visited[i]) {
                if (detectCycle(i, adj, visited)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends