// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if (start == end) return 0;
        
        int mod = 100000;
        vector<int> steps(100000, 1e9);
        queue<pair<int, int>> q;
        q.push({start, 0});
        steps[start] = 0;
        
        while (!q.empty()) {
            int node = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            for (int n : arr) {
                int num = (node * n) % mod;
                if (cnt + 1 < steps[num]) {
                    steps[num] = cnt + 1;
                    if (num == end) return cnt + 1;
                    q.push({num, cnt + 1});
                }
            }
        }
        return -1;
    }
};
