class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    area = max(area, find(points[i], points[j], points[k]));
                }
            }
        }
        return area;
    }
    double find(vector<int> P, vector<int> Q, vector<int> R) {
        return (0.5) * abs((P[0] * (Q[1] - R[1])) + (Q[0] * (R[1] - P[1])) +
                           (R[0] * (P[1] - Q[1])));
    }
};
