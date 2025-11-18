class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = 0;
        for (int m : machines) {
            total += m;
        }
        
        // If total cannot be evenly distributed
        if (total % n != 0) return -1;
        
        int avg = total / n;
        int result = 0;
        int balance = 0;
        
        for (int i = 0; i < n; i++) {
            int diff = machines[i] - avg;
            balance += diff;
            // Max of: absolute balance (left-right flow) or diff (one machine output)
            result = max(result, max(abs(balance), diff));
        }
        
        return result;
    }
};