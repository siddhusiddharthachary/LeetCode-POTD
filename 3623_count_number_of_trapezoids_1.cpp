class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1e9 + 7;
        vector<int> segs;
        unordered_map<int, int> mp;
        for (auto point : points) {
            int y = point[1];
            mp[y]++;
        }
        int sum = 0;
        for (auto [x, y] : mp) {
            if (y >= 2) {
                long long k = ((1LL * y * (y - 1) / 2) % MOD);
                segs.push_back(k);
                sum += k;
            }
        }
        int total = 0;
        // for (int i = 0; i < segs.size(); ++i) {
        //     sum = (sum - segs[i]) ;
        //     total += (1LL * segs[i] * sum) ;
        // }
        for (int i = 0; i < segs.size(); ++i) {
            sum = (sum - segs[i] + MOD) % MOD;
            total = (total + (1LL * segs[i] * sum) % MOD) % MOD;
        }
        return total;
    }
};
