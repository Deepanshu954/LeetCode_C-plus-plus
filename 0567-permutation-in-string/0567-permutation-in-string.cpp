class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        // Count frequency in s1
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        
        int windowSize = s1.length();
        
        // Initial window
        for (int i = 0; i < windowSize; i++) {
            s2Count[s2[i] - 'a']++;
        }
        
        if (s1Count == s2Count) return true;
        
        // Slide the window
        for (int i = windowSize; i < s2.length(); i++) {
            s2Count[s2[i] - 'a']++;  // Add new char
            s2Count[s2[i - windowSize] - 'a']--;  // Remove old char
            
            if (s1Count == s2Count) return true;
        }
        
        return false;
    }
};