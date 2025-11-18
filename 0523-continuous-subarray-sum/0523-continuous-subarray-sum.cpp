class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modMap; // remainder -> index
        modMap[0] = -1; // Handle case where subarray starts from index 0
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = sum % k;
            
            if (modMap.count(mod)) {
                // Check if subarray length is at least 2
                if (i - modMap[mod] >= 2) {
                    return true;
                }
            } else {
                modMap[mod] = i;
            }
        }
        
        return false;
    }
};