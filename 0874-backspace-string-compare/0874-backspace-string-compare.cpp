class Solution {
public:
    string process(string s) {
        string result = "";
        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) result.pop_back();
            } else {
                result += c;
            }
        }
        return result;
    }
    
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};