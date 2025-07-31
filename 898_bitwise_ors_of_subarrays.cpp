class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, prev;

        for (int num : arr) {
            unordered_set<int> cur;
            cur.insert(num);

            for (int x : prev) {
                cur.insert(x | num);
            }


            for (int x : cur) {
                res.insert(x);
            }
            prev = cur;
        }

        return res.size();
    }
};
