class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;

        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;

        res += ".";

        unordered_map<long long, int> mp; 
        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                res.insert(mp[rem], "(");
                res += ")";
                return res;
            }
            mp[rem] = res.size();

            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }

        return res;
    }
};
