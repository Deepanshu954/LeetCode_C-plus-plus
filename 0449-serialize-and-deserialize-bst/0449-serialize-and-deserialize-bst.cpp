/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root, result);
        return result;
    }
    
    void serializeHelper(TreeNode* node, string& s) {
        if (!node) return;
        s += to_string(node->val) + ",";
        serializeHelper(node->left, s);
        serializeHelper(node->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> vals;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            if (!item.empty()) {
                vals.push_back(stoi(item));
            }
        }
        int idx = 0;
        return deserializeHelper(vals, idx, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserializeHelper(vector<int>& vals, int& idx, int minVal, int maxVal) {
        if (idx >= vals.size()) return nullptr;
        int val = vals[idx];
        if (val < minVal || val > maxVal) return nullptr;
        
        TreeNode* node = new TreeNode(val);
        idx++;
        node->left = deserializeHelper(vals, idx, minVal, val);
        node->right = deserializeHelper(vals, idx, val, maxVal);
        return node;
    }
};