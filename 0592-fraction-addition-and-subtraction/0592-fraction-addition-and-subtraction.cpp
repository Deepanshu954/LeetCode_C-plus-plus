class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1;
        int i = 0, n = expression.length();
        
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }
            
            int curr_num = 0;
            while (i < n && isdigit(expression[i])) {
                curr_num = curr_num * 10 + (expression[i] - '0');
                i++;
            }
            curr_num *= sign;
            
            i++; // skip '/'
            
            int curr_den = 0;
            while (i < n && isdigit(expression[i])) {
                curr_den = curr_den * 10 + (expression[i] - '0');
                i++;
            }
            
            num = num * curr_den + curr_num * den;
            den = den * curr_den;
            
            int g = abs(__gcd(num, den));
            num /= g;
            den /= g;
        }
        
        return to_string(num) + "/" + to_string(den);
    }
};