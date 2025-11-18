class Solution {
private:
    vector<int> prefixSum;
    
public:
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int total = prefixSum.back();
        int target = rand() % total;
        
        // Binary search for the target
        int left = 0, right = prefixSum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};