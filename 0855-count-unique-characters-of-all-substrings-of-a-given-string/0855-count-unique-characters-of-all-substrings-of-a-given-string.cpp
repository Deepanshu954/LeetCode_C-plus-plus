class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> index(26);
        for (int i = 0; i < s.length(); i++) {
            index[s[i] - 'A'].push_back(i);
        }
        
        int result = 0;
        for (int c = 0; c < 26; c++) {
            vector<int>& pos = index[c];
            for (int i = 0; i < pos.size(); i++) {
                int left = (i > 0) ? pos[i-1] : -1;
                int right = (i < pos.size()-1) ? pos[i+1] : s.length();
                result += (pos[i] - left) * (right - pos[i]);
            }
        }
        
        return result;
    }
};