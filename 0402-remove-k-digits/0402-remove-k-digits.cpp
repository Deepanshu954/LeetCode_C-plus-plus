class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char c : num) {
            while (!result.empty() && k > 0 && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        
        while (k > 0) {
            result.pop_back();
            k--;
        }
        
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        
        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};