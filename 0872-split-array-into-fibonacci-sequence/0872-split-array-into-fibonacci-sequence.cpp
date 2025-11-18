class Solution {
public:
    vector<int> result;
    
    bool backtrack(string& num, int idx, vector<int>& seq) {
        if (idx == num.length() && seq.size() >= 3) {
            result = seq;
            return true;
        }
        
        long long curr = 0;
        for (int i = idx; i < num.length(); i++) {
            // No leading zeros except "0" itself
            if (i > idx && num[idx] == '0') break;
            
            curr = curr * 10 + (num[i] - '0');
            
            // Check 32-bit overflow
            if (curr > INT_MAX) break;
            
            int val = (int)curr;
            
            if (seq.size() < 2) {
                seq.push_back(val);
                if (backtrack(num, i + 1, seq)) return true;
                seq.pop_back();
            } else {
                if ((long long)seq[seq.size()-1] + seq[seq.size()-2] == val) {
                    seq.push_back(val);
                    if (backtrack(num, i + 1, seq)) return true;
                    seq.pop_back();
                } else if ((long long)seq[seq.size()-1] + seq[seq.size()-2] < val) {
                    break;
                }
            }
        }
        
        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        vector<int> seq;
        backtrack(num, 0, seq);
        return result;
    }
};