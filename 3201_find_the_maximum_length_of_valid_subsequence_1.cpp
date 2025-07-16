class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evens = 0, odds = 0, oddEven = 0, evenOdd = 0;
        for (int num : nums) {
            if (num % 2) {
                if (evenOdd % 2)
                    evenOdd++;
                if (oddEven % 2 == 0)
                    oddEven++;
                odds++;
            } else {
                if (oddEven % 2)
                    oddEven++;
                if (evenOdd % 2 == 0)
                    evenOdd++;
                evens++;
            }
        }
        int maxi = 0;
        maxi = max(maxi, oddEven);
        maxi = max(maxi, evenOdd);
        maxi = max(maxi, odds);
        maxi = max(maxi, evens);
        return maxi;
    }
};
