class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If k = 0 or n >= k + maxPts, probability is 1
        if (k == 0 || n >= k + maxPts - 1) return 1.0;
        
        // dp[i] = probability of getting exactly i points
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        
        double windowSum = 1.0; // Sum of probabilities in the sliding window
        double result = 0.0;
        
        for (int i = 1; i <= n; i++) {
            // Probability of reaching i is average of all ways to reach it
            dp[i] = windowSum / maxPts;
            
            // If i is in [k, n], add to result (we stop drawing at k)
            if (i < k) {
                windowSum += dp[i];
            } else {
                result += dp[i];
            }
            
            // Remove the probability that's out of window
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }
        
        return result;
    }
};