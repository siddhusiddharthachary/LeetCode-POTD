class Solution {
public:
    bool isThere(string s, char x) {
        for (char c : s) {
            if (c == x)
                return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (isThere(words[i], x)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
