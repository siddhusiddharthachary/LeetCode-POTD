class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<int> freq;
        for (auto [c, f] : mp) {
            freq.push_back(f);
        }
        if(k>freq.size()) return 0;
        sort(freq.begin(), freq.end());
        int del = 0;
        int i = 0;
        while ((freq.size() - k) > i) {
            del += freq[i];
            i++;
        }
        return del;
    }
};
