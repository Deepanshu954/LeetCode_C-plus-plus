class Solution {
public:
    int count = 0;
    
    void backtrack(int n, int pos, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                backtrack(n, pos + 1, used);
                used[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        backtrack(n, 1, used);
        return count;
    }
};