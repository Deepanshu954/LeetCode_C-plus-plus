class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0, maxLen = 0, left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            maxCount = max(maxCount, ++count[s[right] - 'A']);
            
            while (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};