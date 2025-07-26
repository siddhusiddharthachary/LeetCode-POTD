class Solution {
public:
    typedef long long ll;
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<ll>> conflPoints(n + 1);
        ll validSubarrays = 0;

        for (auto p : conflictingPairs) {
            int a = p[0], b = p[1];
            if (a > b)
                swap(a, b);
            conflPoints[b].push_back(a);
        }

        ll maxGain = 0;
        vector<ll> gain(n + 1, 0);
        ll totalValid = 0;
        ll maxLeft = 0, secondMax = 0;
        for (int r = 1; r <= n; r++) {
            for (int l : conflPoints[r]) {
                if (l > maxLeft) {
                    secondMax = maxLeft;
                    maxLeft = l;
                } else if (l > secondMax) {
                    secondMax = l;
                }
            }
            totalValid += r - maxLeft;
            if (maxLeft > 0) {
                gain[maxLeft] += maxLeft - secondMax;
            }
        }

        for (ll g : gain) {
            // cout << g << endl;
            if (g > maxGain) {
                maxGain = g;
            }
        }
        return totalValid + maxGain;
    }
};
