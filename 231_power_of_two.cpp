//with recursion

class Solution {
public:
    bool recur(int n){
        if(n==1) return true;
        if(n<=0) return false;
        if(n%2!=0) return false;
        return recur(n/2);
    }
    bool isPowerOfTwo(int n) {
        return recur(n);
    }
};

//without loop/recursion

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (__builtin_popcount(n)==1);
    }
};
