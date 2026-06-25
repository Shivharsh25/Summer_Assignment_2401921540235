class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* node) {
        if (node==NULL) return 0;
        int left  = max(dfs(node->left),  0);
        int right = max(dfs(node->right), 0);
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};