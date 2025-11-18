class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                int count = 0;
                int k = i;
                
                // Follow the chain and mark visited
                while (nums[k] != -1) {
                    int next = nums[k];
                    nums[k] = -1;  // Mark as visited
                    k = next;
                    count++;
                }
                
                maxLen = max(maxLen, count);
            }
        }
        
        return maxLen;
    }
};