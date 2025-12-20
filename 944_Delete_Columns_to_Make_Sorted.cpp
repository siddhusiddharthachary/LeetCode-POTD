class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<string> cols(n, "");
        for (auto s : strs) {
            for (int i = 0; i < s.size(); i++) {
                cols[i].push_back(s[i]);
            }
        }
        int cnt = 0;
        for (auto s : cols) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (s != temp)
                cnt++;
        }
        return cnt;
    }
};
