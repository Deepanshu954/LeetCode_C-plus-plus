class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        // dp[i][j][k] = number of valid strings of length i, with j absences, ending with k consecutive lates
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        dp[0][0][0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == 0) continue;
                    // Add P
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][k]) % MOD;
                    // Add A
                    if (j < 1) {
                        dp[i+1][j+1][0] = (dp[i+1][j+1][0] + dp[i][j][k]) % MOD;
                    }
                    // Add L
                    if (k < 2) {
                        dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }
        
        long long result = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }
        return result;
    }
};