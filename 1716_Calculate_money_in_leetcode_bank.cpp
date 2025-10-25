class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int start = 28;
        int last = 28 + (weeks - 1) * 7;
        int amount = weeks * (start + last) / 2;

        int monday = 1 + weeks;
        int lastWeek = 0;
        for (int i = 0; i < (n % 7); i++) {
            lastWeek += (monday + i);
        }
        return (amount + lastWeek);
    }
};
