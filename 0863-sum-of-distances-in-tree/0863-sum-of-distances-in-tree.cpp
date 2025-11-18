class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> count(n, 1);
        vector<int> answer(n, 0);
        
        // Build adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // First DFS: calculate count and initial answer for root
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (int child : graph[node]) {
                if (child != parent) {
                    dfs1(child, node);
                    count[node] += count[child];
                    answer[node] += answer[child] + count[child];
                }
            }
        };
        
        // Second DFS: re-root the tree to calculate answer for all nodes
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int child : graph[node]) {
                if (child != parent) {
                    answer[child] = answer[node] - count[child] + (n - count[child]);
                    dfs2(child, node);
                }
            }
        };
        
        dfs1(0, -1);
        dfs2(0, -1);
        
        return answer;
    }
};