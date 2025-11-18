class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int pairs = 0;
        for (auto& [num, freq] : count) {
            if (k == 0) {
                // Special case: need at least 2 occurrences
                if (freq >= 2) pairs++;
            } else {
                // Check if num + k exists
                if (count.count(num + k)) pairs++;
            }
        }
        
        return pairs;
    }
};