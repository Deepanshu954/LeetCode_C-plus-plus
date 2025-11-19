class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return validateIPv4(queryIP) ? "IPv4" : "Neither";
        } else if (queryIP.find(':') != string::npos) {
            return validateIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }
    
    bool validateIPv4(string ip) {
        int cnt = 0;
        string token = "";
        ip += ".";
        for (char c : ip) {
            if (c == '.') {
                if (token.empty() || token.size() > 3) return false;
                if (token.size() > 1 && token[0] == '0') return false;
                int num = 0;
                for (char ch : token) {
                    if (!isdigit(ch)) return false;
                    num = num * 10 + (ch - '0');
                }
                if (num > 255) return false;
                cnt++;
                token = "";
            } else {
                token += c;
            }
        }
        return cnt == 4;
    }
    
    bool validateIPv6(string ip) {
        int cnt = 0;
        string token = "";
        ip += ":";
        for (char c : ip) {
            if (c == ':') {
                if (token.empty() || token.size() > 4) return false;
                for (char ch : token) {
                    if (!isxdigit(ch)) return false;
                }
                cnt++;
                token = "";
            } else {
                token += c;
            }
        }
        return cnt == 8;
    }
};