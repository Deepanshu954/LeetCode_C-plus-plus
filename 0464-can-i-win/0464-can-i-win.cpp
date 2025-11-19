class Solution {
public:
    unordered_map<int, bool> memo;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal <= 0) return true;
        if (sum < desiredTotal) return false;
        return canWin(maxChoosableInteger, desiredTotal, 0);
    }
    
    bool canWin(int maxInt, int total, int state) {
        if (total <= 0) return false;
        if (memo.find(state) != memo.end()) return memo[state];
        
        for (int i = 1; i <= maxInt; i++) {
            if ((state & (1 << i)) == 0) {
                if (!canWin(maxInt, total - i, state | (1 << i))) {
                    memo[state] = true;
                    return true;
                }
            }
        }
        memo[state] = false;
        return false;
    }
};