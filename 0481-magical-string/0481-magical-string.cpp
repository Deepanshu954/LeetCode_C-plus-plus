class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;
        
        string s = "122";
        int idx = 2;
        
        while (s.size() < n) {
            int count = s[idx++] - '0';
            char next = (s.back() == '1') ? '2' : '1';
            s.append(count, next);
        }
        
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
        }
        
        return ones;
    }
};