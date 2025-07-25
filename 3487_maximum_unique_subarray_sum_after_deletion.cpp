class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0, negs = 0,maxi=INT_MIN;
        set<int> st;
        for (int it : nums) {
            if (it >= 0 && st.find(it) == st.end()) {
                st.insert(it);
                sum += it;
            }
            maxi=max(maxi, it);
        }
        return sum==0?maxi:sum;
    }
};
