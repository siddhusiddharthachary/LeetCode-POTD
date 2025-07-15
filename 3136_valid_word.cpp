class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vowel = 0, cons = 0;
        for (char c : word) {
            if (!isalpha(c) && !isdigit(c))
                return false;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowel++;
            else if (isalpha(c))
                cons++;
        }
        cout<<cons<<endl;
        return vowel && cons ? true : false;
    }
};
