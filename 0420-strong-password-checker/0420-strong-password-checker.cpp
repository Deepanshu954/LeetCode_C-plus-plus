class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }
        
        int missing = !hasLower + !hasUpper + !hasDigit;
        
        if (n < 6) {
            return max(missing, 6 - n);
        }
        
        int replace = 0, one = 0, two = 0;
        for (int i = 2; i < n;) {
            if (password[i] == password[i-1] && password[i-1] == password[i-2]) {
                int length = 2;
                while (i < n && password[i] == password[i-1]) {
                    length++;
                    i++;
                }
                replace += length / 3;
                if (length % 3 == 0) one++;
                if (length % 3 == 1) two++;
            } else {
                i++;
            }
        }
        
        if (n <= 20) {
            return max(missing, replace);
        }
        
        int remove = n - 20;
        replace -= min(remove, one);
        replace -= min(max(remove - one, 0), two * 2) / 2;
        replace -= max(remove - one - 2 * two, 0) / 3;
        
        return remove + max(missing, replace);
    }
};