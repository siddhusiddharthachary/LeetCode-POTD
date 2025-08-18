class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        if (isvalid(cards))
            return true;
        while (next_permutation(cards.begin(), cards.end())) {
            if (isvalid(cards))
                return true;
        }
        return false;
    }

    bool isvalid(vector<int>& cards) {
        double p = cards[0], q = cards[1], r = cards[2], s = cards[3];
        
        if (isvalid(p + q, r, s) || isvalid(p - q, r, s) ||
            isvalid(p * q, r, s) || isvalid(p / q, r, s))
            return true;
        if (isvalid(p, q + r, s) || isvalid(p, q - r, s) ||
            isvalid(p, q * r, s) || isvalid(p, q / r, s))
            return true;
        if (isvalid(p, q, r + s) || isvalid(p, q, r - s) ||
            isvalid(p, q, r * s) || isvalid(p, q, r / s))
            return true;
        
        return false;
    }

    bool isvalid(double p, double q, double r) {
        if (isvalid(p + q, r) || isvalid(p - q, r) || isvalid(p * q, r) ||
            q != 0 && isvalid(p / q, r))
            return true;
        if (isvalid(p, q + r) || isvalid(p, q - r) || isvalid(p, q * r) ||
            r != 0 && isvalid(p, q / r))
            return true;
        return false;
    }

    bool isvalid(double p, double q) {
        if (abs(p + q - 24) <= 1e-5 || abs(p - q - 24) <= 1e-5 ||
            abs(p * q - 24) <= 1e-5 || q != 0 && abs(p / q - 24) <= 1e-5)
            return true;
        return false;
    }
};
