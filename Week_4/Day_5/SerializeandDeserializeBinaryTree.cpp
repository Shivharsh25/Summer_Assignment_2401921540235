class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Helper function for deserialization
    TreeNode* buildTree(stringstream &ss) {
        string str;
        getline(ss, str, ',');

        if (str == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(str));

        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};