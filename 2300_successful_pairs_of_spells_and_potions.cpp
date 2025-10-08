class Solution {
public:
    int bs(long long x, const vector<int>& potions, long long success){
        int  n =potions.size();
        int l = 0, h = n-1;
        while(l<=h){
            int mid = l + (h-l) / 2;
            long long pro = 1LL * x * potions[mid];
            if(pro>=success){
                h=mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());

        for(int i=0;i<n;i++){
            long long x = spells[i];
            int idx = bs(x, potions, success);
            if(idx<m){
                ans[i] = m-idx;
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }
};
