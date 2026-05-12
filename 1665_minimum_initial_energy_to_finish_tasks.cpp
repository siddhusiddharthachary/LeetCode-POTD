class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int energy=0;
        int ans = 0;
        sort(tasks.begin(), tasks.end(),
        [](vector<int>& a, vector<int>& b){
            return (a[1] - a[0]) > (b[1]-b[0]);
        });

        for(auto task:tasks){
            int actual = task[0], minimum = task[1];
            if(energy<minimum){
                int extraNeeded = minimum - energy;
                ans+=extraNeeded;
                energy = minimum;
            }
            energy-=actual;
        }
        return ans;
    }
};
