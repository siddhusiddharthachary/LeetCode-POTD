class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st(s.begin(), s.end());return st.size();
    }
};
