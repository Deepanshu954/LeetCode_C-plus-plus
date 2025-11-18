class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long num = stoll(n);
        
        // Generate candidates
        set<long long> candidates;
        
        // Edge cases: 999...9 and 100...001
        candidates.insert(pow(10, len) + 1);
        candidates.insert(pow(10, len - 1) - 1);
        
        // Get prefix and mirror it
        int mid = (len + 1) / 2;
        long long prefix = stoll(n.substr(0, mid));
        
        // Try prefix, prefix+1, prefix-1
        for (long long i : {prefix - 1, prefix, prefix + 1}) {
            string palin = to_string(i);
            string candidate = palin;
            
            // Mirror the prefix
            for (int j = len % 2 == 0 ? mid - 1 : mid - 2; j >= 0; j--) {
                candidate += palin[j];
            }
            
            candidates.insert(stoll(candidate));
        }
        
        // Remove the original number
        candidates.erase(num);
        
        // Find the closest
        long long closest = -1;
        long long minDiff = LLONG_MAX;
        
        for (long long cand : candidates) {
            long long diff = abs(cand - num);
            if (diff < minDiff || (diff == minDiff && cand < closest)) {
                minDiff = diff;
                closest = cand;
            }
        }
        
        return to_string(closest);
    }
};