class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        function<void(Node*)> dfs = [&](Node* node) {
            if (!node) return;
            for (auto child : node->children) {
                dfs(child);
            }
            result.push_back(node->val);
        };
        
        dfs(root);
        return result;
    }
};