class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[51][51][51];
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }
    
    int dfs(int m, int n, int moves, int row, int col) {
        // If out of bounds, found a path
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        
        // No more moves left
        if (moves == 0) {
            return 0;
        }
        
        // Check memoization
        if (dp[row][col][moves] != -1) {
            return dp[row][col][moves];
        }
        
        long long paths = 0;
        // Try all 4 directions
        paths += dfs(m, n, moves - 1, row + 1, col);
        paths += dfs(m, n, moves - 1, row - 1, col);
        paths += dfs(m, n, moves - 1, row, col + 1);
        paths += dfs(m, n, moves - 1, row, col - 1);
        
        paths %= MOD;
        dp[row][col][moves] = paths;
        return paths;
    }
};