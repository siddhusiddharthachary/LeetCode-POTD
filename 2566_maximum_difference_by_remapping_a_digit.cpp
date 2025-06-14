class Solution {
public:
    int minMaxDifference(int num) {
        string original = to_string(num);
        char firstNon9 = '9';
        for (char c : original) {
            if (c != '9') {
                firstNon9 = c;
                break;
            }
        }
        string maxString = original;
        for (char& c : maxString) {
            if (c == firstNon9) {
                c = '9';
            }
        }
        int maxVal = stoi(maxString);
        char firstChar = original[0];
        string minString = original;
        for (char& c : minString) {
            if (c == firstChar) {
                c = '0';
            }
        }
        int minVal = stoi(minString);
        return maxVal - minVal;
    }
};
