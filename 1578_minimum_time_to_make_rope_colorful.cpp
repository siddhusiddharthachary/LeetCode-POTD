class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char prevChar = colors[0];
        int prevTime = neededTime[0];
        long long ans = 0;
        
        for (int i = 1; i < (int)colors.size(); ++i) {
            if (colors[i] == prevChar) {
                ans += min(prevTime, neededTime[i]);
                prevTime = max(prevTime, neededTime[i]);
            } else {
                prevChar = colors[i];
                prevTime = neededTime[i];
            }
        }

        return (int)ans;
    }
};
