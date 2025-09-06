class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for (auto q : queries) {
            ll start = q[0], end = q[1];
            ll curr = 1, prev = 1;
            ll ops = 0;

            for (ll cost = 1; cost < 17; cost++) {
                if (prev > end)
                    break;
                curr = curr * 4ll;
                ll l = max(start, prev);
                ll r = min(end, curr - 1);

                if (l <= r) {
                    ops += (r - l + 1) * cost;
                }

                prev = curr;
            }

            ans += (ops + 1) / 2;
        }
        return ans;
    }
};
