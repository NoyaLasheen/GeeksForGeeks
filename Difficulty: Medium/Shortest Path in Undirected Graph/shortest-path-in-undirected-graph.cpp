class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        int n = adj.size();
        queue<pair<int, int>> q;
        vector<int> dist(n, 1e9);
        
        q.push({src, 0});
        dist[src] = 0;
        
        while (!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for (auto& nbr : adj[node]) {
                if (dis + 1 < dist[nbr]) {
                    dist[nbr] = dis + 1;
                    q.push({nbr, dis + 1});
                }
            }
        }
        
        for (int &i : dist) {
            if (i == 1e9) i = -1;
        }
        
        return dist;
    }
};