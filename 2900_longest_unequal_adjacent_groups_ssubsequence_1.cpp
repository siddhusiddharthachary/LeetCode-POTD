class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int prev;
        for (int i = 0; i < n; i++) {
            vector<string> temp;
            temp.push_back(words[i]);
            prev = groups[i];
            for (int j = i + 1; j < n; j++) {
                if (groups[j] != prev) {
                    temp.push_back(words[j]);
                    prev = groups[j];
                }
            }
            if (temp.size() > ans.size())
                ans = temp;
        }
        return ans;
    }
};
