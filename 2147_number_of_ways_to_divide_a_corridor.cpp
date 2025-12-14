class Solution {
public:
    int numberOfWays(string corridor) {
        long ans = 1;
        int prev = -1, seats = 0, mod = 1e9 + 7;

        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                if (++seats > 2 && seats % 2 == 1)
                    ans = ans * (i - prev) % mod;
                prev = i;
            }
        }

        return seats > 1 && seats % 2 == 0 ? ans : 0;
    }
};
