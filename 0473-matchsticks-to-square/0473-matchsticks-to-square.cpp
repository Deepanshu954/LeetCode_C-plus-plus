class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int m : matchsticks) sum += m;
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, target);
    }
    
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int idx, int target) {
        if (idx == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= target) {
                sides[i] += matchsticks[idx];
                if (backtrack(matchsticks, sides, idx + 1, target)) return true;
                sides[i] -= matchsticks[idx];
                if (sides[i] == 0) break;
            }
        }
        return false;
    }
};