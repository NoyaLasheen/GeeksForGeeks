class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[v].push_back({u, wt});
            adj[u].push_back({v, wt});
        }
        
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});
        
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            
            for (auto& nbr: adj[node]) {
                int adjNode = nbr.first;
                int edwt = nbr.second;
                
                if (dist[node] + edwt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edwt;
                    parent[adjNode] = node;
                    
                    pq.push({dis + edwt, adjNode});
                }
            }
        }
        
        int node = n;
        vector<int> path;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        
        if (dist[n] == 1e9) return {-1};
        
        vector<int> result = {dist[n]};
        result.insert(result.end(), path.begin(), path.end());
        return result;
        
    }
};