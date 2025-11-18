class Solution {
public:
    bool isSubsequence(string s, string word) {
        int i = 0;
        for (char c : s) {
            if (i < word.length() && word[i] == c) i++;
        }
        return i == word.length();
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        
        for (string& word : dictionary) {
            if (isSubsequence(s, word)) {
                // Update if word is longer, or same length but lexicographically smaller
                if (word.length() > result.length() || 
                    (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }
        
        return result;
    }
};