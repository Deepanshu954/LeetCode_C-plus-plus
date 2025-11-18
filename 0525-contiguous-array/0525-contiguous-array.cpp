class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumMap; // sum -> first index
        sumMap[0] = -1; // Base case
        int maxLen = 0;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1, so equal 0s and 1s means sum = 0
            sum += (nums[i] == 1) ? 1 : -1;
            
            if (sumMap.count(sum)) {
                maxLen = max(maxLen, i - sumMap[sum]);
            } else {
                sumMap[sum] = i;
            }
        }
        
        return maxLen;
    }
};