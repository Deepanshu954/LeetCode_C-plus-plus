class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        
        dp[1].insert(1);
        
        for (int i = 1; i < stones.size(); i++) {
            int stone = stones[i];
            for (int k : dp[stone]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0 && dp.count(stone + jump)) {
                        dp[stone + jump].insert(jump);
                    }
                }
            }
        }
        
        return !dp[stones.back()].empty();
    }
};