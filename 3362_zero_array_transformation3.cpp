class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> requiredQueries;
        priority_queue<int, vector<int>, greater<int>> chosenQueries;

        int usedCnt = 0;
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < queries.size() && queries[j][0] == i) {
                requiredQueries.push(queries[j][1]);
                j++;
            }

            nums[i] -= chosenQueries.size();

            while (nums[i] > 0 && !requiredQueries.empty() &&
                   requiredQueries.top() >= i) {
                usedCnt++;
                chosenQueries.push(requiredQueries.top());
                requiredQueries.pop();
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;

            while (!chosenQueries.empty() && chosenQueries.top() <= i) {
                chosenQueries.pop();
            }
        }
        return queries.size() - usedCnt;
    }
};
