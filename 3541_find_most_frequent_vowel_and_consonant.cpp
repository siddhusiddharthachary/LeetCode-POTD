class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowel,consonant;
        int maxV = 0, maxC = 0;
        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ){
                vowel[c]++;
                maxV = max(maxV,vowel[c]);
            }else{
                consonant[c]++;
                maxC = max(maxC,consonant[c]);
            }
        }
        return maxV+maxC;
    }
};
