class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) return -1;
        
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        
        char genes[] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            
            if (curr == endGene) return steps;
            
            for (int i = 0; i < 8; i++) {
                char original = curr[i];
                for (char c : genes) {
                    if (c == original) continue;
                    curr[i] = c;
                    if (bankSet.count(curr) && !visited.count(curr)) {
                        visited.insert(curr);
                        q.push({curr, steps + 1});
                    }
                }
                curr[i] = original;
            }
        }
        
        return -1;
    }
};