class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky = -1;
        unordered_map<int,int> freq;
        for(int it : arr){
            freq[it]++;
        }
        for(auto [num,f] : freq){
            if(num==f){
                lucky = max(lucky, num);
            }
        }
        return lucky;
    }
};
