class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        function<void(Node*)> dfs = [&](Node* node) {
            if (!node) return;
            result.push_back(node->val);
            for (auto child : node->children) {
                dfs(child);
            }
        };
        
        dfs(root);
        return result;
    }
};