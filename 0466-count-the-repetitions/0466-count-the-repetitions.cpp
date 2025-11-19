class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int s1cnt = 0, s2cnt = 0, idx = 0;
        unordered_map<int, pair<int, int>> mp;
        
        while (s1cnt < n1) {
            s1cnt++;
            for (char c : s1) {
                if (c == s2[idx]) {
                    idx++;
                    if (idx == s2.size()) {
                        s2cnt++;
                        idx = 0;
                    }
                }
            }
            
            if (mp.count(idx)) {
                int preS1 = mp[idx].first;
                int preS2 = mp[idx].second;
                int patternS1 = s1cnt - preS1;
                int patternS2 = s2cnt - preS2;
                int repeat = (n1 - preS1) / patternS1;
                int patS1 = preS1 + repeat * patternS1;
                int patS2 = preS2 + repeat * patternS2;
                
                while (patS1 < n1) {
                    patS1++;
                    for (char c : s1) {
                        if (c == s2[idx]) {
                            idx++;
                            if (idx == s2.size()) {
                                patS2++;
                                idx = 0;
                            }
                        }
                    }
                }
                return patS2 / n2;
            }
            mp[idx] = {s1cnt, s2cnt};
        }
        return s2cnt / n2;
    }
};