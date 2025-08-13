// Recursion code

class Solution {
public:
    bool recur(int n) {
        if (n == 1)
            return true;
        if (n < 1)
            return false;
        if (n % 3 != 0)
            return false;

        return recur(n / 3);
    }
    bool isPowerOfThree(int n) { return recur(n); }
};


// 1 line code OPTIMAL

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 &&  (1162261467%n==0);
    }
};

