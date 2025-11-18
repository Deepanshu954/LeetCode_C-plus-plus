class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        // For k consecutive numbers: k*x + k*(k-1)/2 = n
        // So: x = (n - k*(k-1)/2) / k
        // x must be positive integer
        for (int k = 1; k * (k - 1) / 2 < n; k++) {
            if ((n - k * (k - 1) / 2) % k == 0) {
                count++;
            }
        }
        return count;
    }
};