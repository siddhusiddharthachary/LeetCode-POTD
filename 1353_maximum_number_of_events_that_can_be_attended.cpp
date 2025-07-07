class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), i = 0, cnt = 0, day = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        while (i < n || !pq.empty()) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
            day++;
        }
        return cnt;
    }
};
