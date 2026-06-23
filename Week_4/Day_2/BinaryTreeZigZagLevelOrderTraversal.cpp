class Solution {
public:
    int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
void NthOrder(TreeNode* root,int curr,int level,vector<int>& v){  
if(level%2!=0){
    if(root==NULL) return;
    if(curr == level){      // root
        v.push_back(root->val);
        return;
    } 
    NthOrder(root->left,curr+1,level,v);  // left
    NthOrder(root->right,curr+1,level,v); // right
}
else{
    if(root==NULL) return;
    if(curr == level){      // root
        v.push_back(root->val);
        return;
    } 
    NthOrder(root->right,curr+1,level,v); // right
    NthOrder(root->left,curr+1,level,v);  // left
}
}
void lOrder(TreeNode* root,vector<vector<int>>& ans){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        vector<int> v;
        NthOrder(root,1,i,v);
        ans.push_back(v);
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
    }
};