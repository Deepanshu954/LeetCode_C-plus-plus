class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        
        // (a1 + b1i) * (a2 + b2i) = (a1*a2 - b1*b2) + (a1*b2 + b1*a2)i
        int real = a1 * a2 - b1 * b2;
        int imag = a1 * b2 + b1 * a2;
        
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};