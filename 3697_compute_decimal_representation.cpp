class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int p = 0;
        string s = to_string(n);
        int sz = s.size();
        for(int i = sz-1;i>=0;i--){
            if(s[i]!='0') ans.push_back((s[i]-'0') * pow(10,p));
            p++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
