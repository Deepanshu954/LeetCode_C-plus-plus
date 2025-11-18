class Solution {
public:
    int findLUSlength(string a, string b) {
        // If strings are equal, no uncommon subsequence exists
        if (a == b) return -1;
        
        // If strings are different, the longer one is the uncommon subsequence
        return max(a.length(), b.length());
    }
};