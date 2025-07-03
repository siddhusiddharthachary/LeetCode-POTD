class Solution {
public:
    char kthCharacter(int k) {
        int cnt = __builtin_popcount(k - 1);
        return 'a' + cnt;
    }
};
