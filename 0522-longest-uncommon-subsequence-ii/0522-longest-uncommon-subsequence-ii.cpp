class Solution {
public:
    bool isSubsequence(string a, string b) {
        int i = 0;
        for (char c : b) {
            if (i < a.length() && a[i] == c) i++;
        }
        return i == a.length();
    }
    
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        
        for (int i = 0; i < strs.size(); i++) {
            bool isUncommon = true;
            
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            
            if (isUncommon) {
                maxLen = max(maxLen, (int)strs[i].length());
            }
        }
        
        return maxLen;
    }
};