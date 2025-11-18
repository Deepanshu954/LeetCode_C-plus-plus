class Solution {
public:
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[1] - a[1]) * (c[0] - b[0]) - (b[0] - a[0]) * (c[1] - b[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) return trees;
        
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> hull;
        
        // Build lower hull
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 && orientation(hull[hull.size()-2], hull[hull.size()-1], trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        
        // Build upper hull
        int lower_size = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > lower_size && orientation(hull[hull.size()-2], hull[hull.size()-1], trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        
        hull.pop_back();
        
        // Remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        
        return hull;
    }
};