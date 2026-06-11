
class Solution {
public:
    string decode(string &s, int &i) {
        string ans = "";
        while(i < s.size() && s[i] != ']') {
            if(isalpha(s[i])) {
                ans += s[i++];
            }
            else {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++; // skip '['
                string temp = decode(s, i);
                i++; // skip ']'
                while(num--) {
                    ans += temp;
                }
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};