class Solution {
public:
    int reversed(int n) {
        string s = to_string(n);
        while (s.back() == '0') {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        int ans = stoi(s);
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int rev = reversed(nums[i]);
            if (mp.find(rev) != mp.end()) {
                ans = min(ans, abs(i - mp[rev].back()));
            }
            mp[nums[i]].push_back(i);
        }
        return ans==INT_MAX ? -1: ans;
    }
};
