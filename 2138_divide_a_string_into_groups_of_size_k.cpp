class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        for(int i=0;i<n;i+=k){
            string curr = s.substr(i,k);
            ans.push_back(curr);
        }
        while(ans.back().size()<k){
            ans.back().push_back(fill);
        }
        return ans;
    }
};
