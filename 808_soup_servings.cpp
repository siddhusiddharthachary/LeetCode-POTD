class Solution {
public:
    vector<pair<int, int>> ops = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> dp;
    double recur(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1;
        } else if (b <= 0) {
            return 0.0;
        }
        if (dp[a][b] != -1)
            return dp[a][b];
        double res = 0.0;
        for (auto [p1, p2] : ops) {
            res += recur(a - p1, b - p2);
        }
        return dp[a][b] = 0.25 * res;
    }
    double soupServings(int n) {
        if(n>=4500) return 1;
        dp.resize(n + 1, vector<double>(n + 1, -1));
        return recur(n, n);
    }
};
