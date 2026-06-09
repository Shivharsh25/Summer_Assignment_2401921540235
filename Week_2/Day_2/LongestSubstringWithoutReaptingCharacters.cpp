class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> idx(128,0);
        int maxLen = 0, left = 0;

        for (int right = 0; right < s.size(); right++) {
            left = max(left, idx[s[right]]);
            maxLen = max(maxLen, right - left + 1);
            idx[s[right]] = right + 1;  // store next position
        }
        return maxLen;
    }
};