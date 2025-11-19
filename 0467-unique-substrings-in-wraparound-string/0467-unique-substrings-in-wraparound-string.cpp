class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> cnt(26, 0);
        int len = 1;
        
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && (s[i] - s[i-1] == 1 || s[i-1] - s[i] == 25)) {
                len++;
            } else {
                len = 1;
            }
            cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], len);
        }
        
        int result = 0;
        for (int c : cnt) {
            result += c;
        }
        return result;
    }
};