class Solution {
public:
typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long maxi = LLONG_MIN;
        vector<ll> priceOnes(n, 0), profits(n, 0);
        profits[0] = prices[0] * strategy[0];
        priceOnes[0] = prices[0];
        for (int i = 1; i < n; i++) {
            priceOnes[i] = prices[i] + priceOnes[i - 1];
            profits[i] = (prices[i] * strategy[i]) + profits[i - 1];
        }
        maxi = max(maxi, profits[n-1]);
        for (int i = 0; i < (n - k + 1); i++) {
            long long profit = 0;
            if (i == 0) {
                profit = (priceOnes[k - 1] - priceOnes[(k / 2) - 1]) +
                         (profits[n - 1] - profits[k - 1]);
            } else if (i == (n - k)) {
                profit = (profits[i - 1]) +
                         (priceOnes[n - 1] - priceOnes[n - (k / 2) - 1]);
            } else {
                profit =
                    (profits[i - 1] + (profits[n - 1] - profits[i + k - 1])) +
                    (priceOnes[i + k - 1] - priceOnes[i + (k / 2) - 1]);
            }
            maxi = max(maxi, profit);
        }
        return maxi;
    }
};
