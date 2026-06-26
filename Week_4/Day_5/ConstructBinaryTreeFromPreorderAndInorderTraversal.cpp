class Solution {
public:
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int start, int end) {
        if (start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int i;
        for (i = start; i <= end; i++) {
            if (inorder[i] == root->val)
                break;
        }
        root->left = build(preorder, inorder, start, i - 1);
        root->right = build(preorder, inorder, i + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};