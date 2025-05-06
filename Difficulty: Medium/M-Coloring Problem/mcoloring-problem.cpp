//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    bool canColor(vector<int>& colors, int color, int node, vector<set<int>> &adj) {
        for (auto& nbr: adj[node]) {
            if (colors[nbr] == color) return false;
        }
        
        return true;
    }
    
    bool colorHelp(vector<set<int>> &adj, int m, vector<int>& colors, int node, int v) {
        if (node == v) return true;
        
        for (int i = 1; i <= m; i++) {
            if (canColor(colors, i, node, adj)) {
                colors[node] = i;
                if (colorHelp(adj, m, colors, node + 1, v)) {
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<set<int>> adj(v);
        
        for (auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            
            if (i >=0 && i < v && j >= 0 && j < v) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
            
        }
        
        vector<int> colors(v, 0);
        
        return colorHelp(adj, m, colors, 0, v);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            edges.push_back({v, u});
        }
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        cout << (obj.graphColoring(V, edges, m) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends