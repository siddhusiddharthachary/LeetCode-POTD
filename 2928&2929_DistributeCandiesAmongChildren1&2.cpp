// 1

class Solution {
public:
    int distributeCandies(int n, int limit) {
        long long result = 0;
        for (int i = 0; i <= min(n,limit); i++) {
            for (int j = 0; j <= min(n - i, limit); j++) {
                int k = n - i - j;
                if (k <= limit) {
                    result += 1;
                }
            }
        }
        return result;
    }
};

//2

class Solution {
public:
    int distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            long long remaining = n - i;
            if (remaining > (2 * limit))
                continue;
            long long maxi = (limit < remaining) ? limit : remaining;
            remaining = remaining - maxi;
            ans += max(0LL, maxi - remaining + 1);
        }
        return ans;
    }
};
