class Solution {
public:
    bool scoreBalance(string s) {
        int n  =s.size();
        vector<int> preSum(n,0);
        preSum[0] = s[0]-'a'+1;
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + (s[i]-'a' + 1);
        }
        for(int i=0;i<n-1;i++){
            if((preSum[n-1]-preSum[i]) == preSum[i]) return true;
        }
        return false;
    }
};
