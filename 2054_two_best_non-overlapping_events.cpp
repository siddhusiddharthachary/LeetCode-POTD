class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, bool, int>> p;
        int ans = 0, prevMax = 0;

        for (auto& event : events) {
            int s = event[0], e = event[1], v = event[2];
            p.emplace_back(s, true, v);
            p.emplace_back(e + 1, false, v);
        }

        sort(p.begin(), p.end());

        for (const auto& [time, is_start, currVal] : p) {
            if (is_start) {
                ans = max(ans, prevMax + currVal);
            } else {
                prevMax = max(prevMax, currVal);
            }
        }

        return ans;
    }
};
