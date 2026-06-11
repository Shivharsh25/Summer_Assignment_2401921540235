class Solution {
public:
void gen_paren(string s,vector<string> &v,int open , int close, int n){
    if(close==n){
            v.push_back(s);
        return;
    }
    if(open<n) gen_paren(s+'(',v,open+1,close,n);
    if(close<open) gen_paren(s+')',v,open,close+1,n);
}
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        gen_paren("",v,0,0,n);
        return v;
    }
};