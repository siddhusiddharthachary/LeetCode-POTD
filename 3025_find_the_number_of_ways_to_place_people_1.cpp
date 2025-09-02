class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            auto& A = points[i]; 
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                auto& B = points[j];

                if (!(A[0] <= B[0] && A[1] >= B[1])) continue;

                bool blocked = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    auto& P = points[k];
                    if (A[0] <= P[0] && P[0] <= B[0] &&
                        B[1] <= P[1] && P[1] <= A[1]) {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) ans++;
            }
        }
        return ans;
    }
};
