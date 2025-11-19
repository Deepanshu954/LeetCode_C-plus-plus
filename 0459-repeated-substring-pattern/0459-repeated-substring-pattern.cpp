class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                bool valid = true;
                for (int i = len; i < n; i += len) {
                    if (s.substr(i, len) != sub) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
        }
        return false;
    }
};