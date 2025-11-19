/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return pathSumFrom(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    int pathSumFrom(TreeNode* node, long long sum) {
        if (!node) return 0;
        int count = 0;
        if (node->val == sum) count++;
        count += pathSumFrom(node->left, sum - node->val);
        count += pathSumFrom(node->right, sum - node->val);
        return count;
    }
};