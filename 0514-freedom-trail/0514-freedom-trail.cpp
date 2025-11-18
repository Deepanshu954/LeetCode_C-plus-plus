class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        
        // Build position map for each character
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[ring[i]].push_back(i);
        }
        
        // Base case: starting at position 0
        dp[0][0] = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == INT_MAX) continue;
                
                // Try all positions of current key character
                for (int k : pos[key[i]]) {
                    int dist = abs(k - j);
                    int minDist = min(dist, n - dist);
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + minDist + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[m][j]);
        }
        
        return result;
    }
};