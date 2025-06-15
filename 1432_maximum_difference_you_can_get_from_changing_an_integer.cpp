class Solution {
public:
    int maxDiff(int num) {
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
        char changeChar = 'a';
        for (char c : original) {
            if (firstChar == '1' && c != '0' && c != firstChar) {
                changeChar = c;
                break;
