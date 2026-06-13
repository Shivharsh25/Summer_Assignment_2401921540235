class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;      // read pointer
        int idx = 0;  // write pointer
        while (i < chars.size()) {
            char curr = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == curr) {
                count++;
                i++;
            }
            chars[idx++] = curr;
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[idx++] = c;
                }
            }
        }
        return idx;
    }
};