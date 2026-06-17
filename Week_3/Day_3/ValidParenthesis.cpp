class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // if stack empty → no matching opening
                if (st.empty())
                    return false;
                // check matching
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop(); // valid pair
            }
        }
        return st.empty(); // must be empty at end
    }
};