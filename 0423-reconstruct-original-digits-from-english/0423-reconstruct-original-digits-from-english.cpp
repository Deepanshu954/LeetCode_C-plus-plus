class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26);
        for (char c : s) count[c - 'a']++;
        
        vector<int> digits(10);
        digits[0] = count['z' - 'a'];
        digits[2] = count['w' - 'a'];
        digits[4] = count['u' - 'a'];
        digits[6] = count['x' - 'a'];
        digits[8] = count['g' - 'a'];
        digits[3] = count['h' - 'a'] - digits[8];
        digits[5] = count['f' - 'a'] - digits[4];
        digits[7] = count['s' - 'a'] - digits[6];
        digits[9] = count['i' - 'a'] - digits[5] - digits[6] - digits[8];
        digits[1] = count['n' - 'a'] - digits[7] - 2 * digits[9];
        
        string result;
        for (int i = 0; i < 10; i++) {
            result += string(digits[i], '0' + i);
        }
        return result;
    }
};