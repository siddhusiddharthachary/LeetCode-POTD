class Solution {
public:
    bool isValid(long long num, unordered_map<char,int> mp){
        string s  = to_string(num);
        unordered_map<char,int> mp2;
        for(char c : s){
            mp2[c]++;
        }
        return mp2==mp;
    }
    bool reorderedPowerOf2(int n) {
        vector<long long> powersOf2;
        long long power = 1;
        for(int i=0;i<33;i++){
            powersOf2.push_back(power);
            power*=2;
        }
        unordered_map<char,int> mp;
        string s = to_string(n);
        for(char c : s){
            mp[c]++;
        }
        for(int i=0;i<powersOf2.size();i++){
            if(isValid(powersOf2[i],mp)) return true;
        }
        return false;
    }
};
