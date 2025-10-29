//1. 
class Solution {
public:
bool isSet(int N){
    if (N == pow(2, __builtin_popcount(N)) - 1)
        return true;
    return false;
}

    int smallestNumber(int n) {
        while(!isSet(n)){
            n++;
        }
        return n;
    }
};


2.
class Solution {
public:
    int smallestNumber(int n) {
        while(n!=pow(2,__builtin_popcount(n))-1){
            n++;
        }
        return n;
    }
};
