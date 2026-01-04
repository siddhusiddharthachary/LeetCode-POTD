class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0, curr = 0;
            for (int j = 1; (j * j) <= (nums[i]); j++) {
                if (nums[i] % j == 0) {
                    int d1 = j;
                    int d2 = nums[i] / j;

                    if (d1 == d2) {
                        cnt += 1;
                        curr += d1;
                    } else {
                        cnt += 2;
                        curr += (d1 + d2);
                    }

                    if (cnt > 4)
                        break;
                }
            }
            if (cnt == 4)
                ans += curr;
        }

        return ans;
    }
};
