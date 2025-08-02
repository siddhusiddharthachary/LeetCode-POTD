class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for (int fruit : basket1) freq[fruit]++;
        for (int fruit : basket2) freq[fruit]--;

        vector<int> excessA, excessB;
        int minFruit = INT_MAX;

        for (auto& [fruit, diff] : freq) {
            if (diff % 2 != 0) return -1;
            minFruit = min(minFruit, fruit);
            int count = abs(diff) / 2;
            for (int i = 0; i < count; ++i) {
                if (diff > 0) excessA.push_back(fruit);
                else excessB.push_back(fruit);
            }
        }

        sort(excessA.begin(), excessA.end());
        sort(excessB.rbegin(), excessB.rend());

        long long cost = 0;
        for (int i = 0; i < excessA.size(); ++i) {
            int a = excessA[i], b = excessB[i];
            cost += min({a, b, 2 * minFruit});
        }

        return cost;
    }
};
