class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            // Email
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            int atPos = s.find('@');
            return s[0] + string("*****") + s.substr(atPos - 1);
        } else {
            // Phone
            string digits;
            for (char c : s) {
                if (isdigit(c)) digits += c;
            }
            int n = digits.length();
            string last4 = digits.substr(n - 4);
            if (n == 10) {
                return "***-***-" + last4;
            } else {
                return "+" + string(n - 10, '*') + "-***-***-" + last4;
            }
        }
    }
};