class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int i = 0;
        
        while (i < s.length()) {
            int start = i;
            while (i < s.length() && s[i] == s[start]) {
                i++;
            }
            if (i - start >= 3) {
                result.push_back({start, i - 1});
            }
        }
        
        return result;
    }
};