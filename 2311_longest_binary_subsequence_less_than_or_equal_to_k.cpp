class Solution {
public:int longestSubsequence(string s, int k) {
        int j = 0;
        int val = 0;
        int size = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (val + ((s[i] - '0') * pow(2, j)) > k) {
                j++;
                continue;
            } else {
                val += ((s[i] - '0') * pow(2, j));
                size++;
            }
            j++;
        }
        return size;
    }
};
