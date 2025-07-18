class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long sz = nums.size();
        vector<long long> lSum(sz, 0), rSum(sz, 0);
        int n = sz / 3;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        priority_queue<long long> maxHeap;
        long long sum = 0;
        for (int i = nums.size() - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) {
                rSum[i] = sum;
            }
        }
        sum = 0;
        long long mini = LLONG_MAX;
        for (int i = 0; i < sz - n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) {
                lSum[i] = sum;
            }
        }
        for (int i = 0; i < sz - n; i++) {
            if (lSum[i] != 0 && rSum[i + 1] != 0)
                mini = min(mini, lSum[i] - rSum[i + 1]);
        }
        return mini;
    }
};
