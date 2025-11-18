class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 2;
        
        while (i >= 0 && s[i] >= s[i+1]) {
            i--;
        }
        
        if (i < 0) return -1;
        
        int j = s.length() - 1;
        while (j > i && s[j] <= s[i]) {
            j--;
        }
        
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        
        long long result = stoll(s);
        return (result > INT_MAX) ? -1 : result;
    }
};