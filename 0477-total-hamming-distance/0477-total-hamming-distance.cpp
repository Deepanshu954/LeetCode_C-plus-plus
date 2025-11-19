class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (int num : nums) {
                ones += (num >> i) & 1;
            }
            result += ones * (n - ones);
        }
        
        return result;
    }
};