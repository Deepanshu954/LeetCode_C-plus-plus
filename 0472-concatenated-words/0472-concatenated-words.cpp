class Solution {
public:
    unordered_set<string> dict;
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string& word : words) dict.insert(word);
        vector<string> result;
        
        for (string& word : words) {
            if (canForm(word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool canForm(string& word) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = (i == n ? 1 : 0); j < i; j++) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};