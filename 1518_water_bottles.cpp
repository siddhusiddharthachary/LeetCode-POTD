// loop solution
class Solution {
public:
    int numWaterBottles(int numBottles, int nE) {
        int ans = 0, e = 0, f = numBottles;
        ans+=f;
        e=f;
        while ((e)>=nE) {
            int ini = e;
            f = (e/nE);
            ans+=f;
            e=(ini - (f*nE)) + f;
        }
        return ans;
    }
};

//O(1) solution
class Solution {
public:
    int numWaterBottles(int b, int nE) {
        return ((b*nE)-1)/(nE-1);
    }
};
