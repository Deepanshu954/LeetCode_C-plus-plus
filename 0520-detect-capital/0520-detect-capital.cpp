class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int capitals = 0;
        
        for (char c : word) {
            if (isupper(c)) capitals++;
        }
        
        // All capitals, all lowercase, or only first letter capital
        return capitals == n || capitals == 0 || (capitals == 1 && isupper(word[0]));
    }
};