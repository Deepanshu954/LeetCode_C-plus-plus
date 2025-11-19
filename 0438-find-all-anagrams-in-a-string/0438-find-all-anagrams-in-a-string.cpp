class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            
            if (i >= p.length()) {
                sCount[s[i - p.length()] - 'a']--;
            }
            
            if (i >= p.length() - 1 && pCount == sCount) {
                result.push_back(i - p.length() + 1);
            }
        }
        
        return result;
    }
};