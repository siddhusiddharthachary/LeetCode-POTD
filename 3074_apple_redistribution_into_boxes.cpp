class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cnt = 0;
        int total = accumulate(apple.begin(), apple.end(), 0);
        for (int i = 0; i < capacity.size() && total > 0; i++) {
            total -= capacity[i];
            cnt++;
        }
        return cnt;
    }
};
