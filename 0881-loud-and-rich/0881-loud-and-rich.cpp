class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        
        // Build graph: if a is richer than b, add edge from b to a
        for (auto& r : richer) {
            graph[r[1]].push_back(r[0]);
        }
        
        vector<int> answer(n, -1);
        
        function<int(int)> dfs = [&](int x) {
            if (answer[x] != -1) return answer[x];
            answer[x] = x;
            for (int y : graph[x]) {
                int candidate = dfs(y);
                if (quiet[candidate] < quiet[answer[x]]) {
                    answer[x] = candidate;
                }
            }
            return answer[x];
        };
        
        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        
        return answer;
    }
};