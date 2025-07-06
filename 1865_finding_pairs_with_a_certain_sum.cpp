class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (auto it : n2) {
            freq[it]++;
        }
    }

    void add(int index, int val) {
        freq[n2[index]]--;
        if(freq[n2[index]]==0){
            freq.erase(n2[index]);
        }
        n2[index] += val;
        freq[n2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for(auto it : n1){
            if(it>tot) continue;
            int diff = tot - it;
            if(freq.find(diff)!=freq.end()){
                cnt += freq[diff];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
