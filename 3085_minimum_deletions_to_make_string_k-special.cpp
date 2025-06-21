class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }
        int ans = n;
        for (auto [minChar, f1] : freq) {
            int del = 0;
            for (auto [currChar, f2] : freq) {
                int diff = f2 - f1;
                if (f1 > f2) {
                    del += f2;
                } else if (diff > k) {
                    del += (f2 - f1 - k);
                }
            }
            ans = min(ans, del);
        }
        return ans;
    }
};
