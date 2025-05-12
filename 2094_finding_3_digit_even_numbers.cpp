class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> digitFrequency;
        for (int digit : digits) {
            digitFrequency[digit]++;
        }

        vector<int> result;

        for (int number = 100; number <= 999; ++number) {
            if (number % 2 != 0)
                continue;

            unordered_map<int, int> currentFrequency;
            int temp = number;

            while (temp > 0) {
                int digit = temp % 10;
                currentFrequency[digit]++;
                temp /= 10;
            }

            bool canForm = true;
            for (auto& [digit, count] : currentFrequency) {
                if (digitFrequency[digit] < count) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                result.push_back(number);
            }
        }

        return result;
    }
};
