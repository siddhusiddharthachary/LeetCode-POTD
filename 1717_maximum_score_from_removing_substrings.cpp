class Solution {
public:
    int remove(string& s, int score, char one, char two) {
        stack<pair<char,int>> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (!st.empty() && st.top().first == one && c == two) {
                int idx = st.top().second;
                s[idx] = '.';
                s[i] = '.';
                st.pop();
                ans += score;
            } else if(c!='.'){
                st.push({c,i});
            }
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x>y) {
            res += remove(s, x, 'a', 'b');
            res += remove(s, y, 'b', 'a');
        } else {
            res += remove(s, y, 'b', 'a');
            res += remove(s, x, 'a', 'b');
        }
        return res;
    }
};
