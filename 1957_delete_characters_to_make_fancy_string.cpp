class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3) return s;
        string ans;
         for (int i = 0; i < s.size(); i++) {
            int sz=ans.size();
            if(sz>1 && s[i]==ans[sz-1] && s[i]==ans[sz-2]) continue;
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
