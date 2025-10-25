class Solution {
public:
    string op1(string s, int k) {
        reverse(s.begin(), s.begin()+k);
        return s;
    }
    string op2(string s, int k) {
        int n = s.length();
        reverse(s.end() - k, s.end()); 
        return s;
    }
    string lexSmallest(string s) {
        string ans = s;
        for (int k = 1; k <= s.size(); k++) {
            string s1 = op1(s, k), s2 = op2(s, k);
            ans = min(ans, s1);
            ans = min(ans, s2);
        }
        return ans;
    }
};
