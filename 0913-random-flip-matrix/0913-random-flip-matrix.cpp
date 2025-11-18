class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map; // Maps virtual index to actual index
    
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int idx = rand() % total;
        int actualIdx = map.count(idx) ? map[idx] : idx;
        
        // Swap with last available position
        total--;
        map[idx] = map.count(total) ? map[total] : total;
        
        return {actualIdx / n, actualIdx % n};
    }
    
    void reset() {
        total = m * n;
        map.clear();
    }
};