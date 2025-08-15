//loop approach
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        while(n%4==0){
            n/=4;
        }
        return n==1;
    }
};

//recursion approach
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n==0 || n%4!=0) return false;
        return isPowerOfFour(n/4);
    }
};

//bit manipulation with loop
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        if (__builtin_popcount(n) == 1) {
            long long j = 1, i = 2;
            while (i <= 32) {
                if (i < 32 && ((n >> i) & 1))
                    return true;
                i = 2 * j;
                j++;
            }
        }
        return false;
    }
};

// 1 line code with bit manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (__builtin_popcount(n)==1) && (n & 0x55555555);
    }
};
