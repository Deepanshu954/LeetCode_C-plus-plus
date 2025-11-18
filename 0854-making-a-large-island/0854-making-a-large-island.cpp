class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> area;
        int islandId = 2;
        int maxArea = 0;
        
        // DFS to find all islands and their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    area[islandId] = size;
                    maxArea = max(maxArea, size);
                    islandId++;
                }
            }
        }
        
        // Try changing each 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    if (i > 0 && grid[i-1][j] > 1) neighbors.insert(grid[i-1][j]);
                    if (i < n-1 && grid[i+1][j] > 1) neighbors.insert(grid[i+1][j]);
                    if (j > 0 && grid[i][j-1] > 1) neighbors.insert(grid[i][j-1]);
                    if (j < n-1 && grid[i][j+1] > 1) neighbors.insert(grid[i][j+1]);
                    
                    int newArea = 1;
                    for (int id : neighbors) {
                        newArea += area[id];
                    }
                    maxArea = max(maxArea, newArea);
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        return 1 + dfs(grid, i+1, j, id) + dfs(grid, i-1, j, id) + 
                   dfs(grid, i, j+1, id) + dfs(grid, i, j-1, id);
    }
};