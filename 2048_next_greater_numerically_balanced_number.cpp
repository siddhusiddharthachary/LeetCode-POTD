class Solution {
public:
    bool isValid(int num){
        string s = to_string(num);
        vector<int> freq(10,0);
        for(auto c: s){
            freq[c-'0']+=1;
        }
        for(int i=0;i<10;i++){
            if(freq[i]>0 && freq[i]!=i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(isValid(i)) return i;
        }
        return 0;
    }
};
