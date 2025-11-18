class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        
        // Collect positions of all 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        // Use a map to count how many times each translation vector occurs
        map<pair<int, int>, int> count;
        
        // For each pair of 1s, calculate the translation vector needed
        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                count[{dx, dy}]++;
            }
        }
        
        // Find the maximum overlap
        int maxOverlap = 0;
        for (auto& p : count) {
            maxOverlap = max(maxOverlap, p.second);
        }
        
        return maxOverlap;
    }
};