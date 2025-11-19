class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2.0 * (long long)n + 0.25) - 0.5);
    }
};