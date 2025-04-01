//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dis(n, 100000);
        vector<int> ans;
        queue<int> q;
        dis[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto& nbr : adj[node]) {
                if (dis[node] + 1 < dis[nbr]) {
                    dis[nbr] = dis[node] + 1;
                    q.push(nbr);
                }
            }
        }
        
        for (int i : dis) {
            if (i == 100000) ans.push_back(-1);
            else ans.push_back(i);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends