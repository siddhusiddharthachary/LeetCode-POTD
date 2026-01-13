class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = 0;
        for (auto& sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }
        
        while (high > low) {
            double mid = (low + high) / 2, upper = 0, lower = 0;
            for (auto& sq : squares) {
                double y = sq[1], len = sq[2], top = y + len;
                if (top <= mid) lower += len * len;
                else if (y >= mid) upper += len * len;
                else {
                    double below = mid - y, above = top - mid;
                    lower += below * len, upper += above * len;
                }
            }
            (upper > lower) ? (low = mid + 1e-5) : (high = mid - 1e-5);
        }
        return low;
    }
};
