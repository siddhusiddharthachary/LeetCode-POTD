class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Case 1: Nothing required
        if (need1 == 0 && need2 == 0) {
            return 0;
        }

        // Case 2: Buying separately is always cheaper or equal
        if (cost1 + cost2 <= costBoth) {
            return (long long)need1 * cost1 + (long long)need2 * cost2;
        }

        // Base answer
        long long minTotalCost = LLONG_MAX;

        // Use "both" items only for the overlapping requirement
        long long overlapCount = min(need1, need2);

        long long costUsingOverlapBoth =
            overlapCount * costBoth +
            (need1 - overlapCount) * cost1 +
            (need2 - overlapCount) * cost2;

        minTotalCost = min(minTotalCost, costUsingOverlapBoth);

        // Use "both" items for everything (even if one side overfills)
        long long maxRequired = max(need1, need2);
        long long costUsingOnlyBoth = maxRequired * costBoth;

        minTotalCost = min(minTotalCost, costUsingOnlyBoth);

        return minTotalCost;
    }
};
