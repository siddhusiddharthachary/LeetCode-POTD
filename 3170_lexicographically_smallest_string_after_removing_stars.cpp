class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        map<char, vector<int>> freq;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]))
                freq[s[i]].push_back(i);
            auto it = freq.begin();
            if (s[i] == '*') {
                int idx = it->second.back();
                s[idx] = '*';
                it->second.pop_back();
                if (it->second.empty()) {
                    freq.erase(it);
                }
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]))
                ans.push_back(s[i]);
        }
        return ans;
    }
};
