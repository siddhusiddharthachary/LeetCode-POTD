class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        int n = baskets.size();
        int segSize = sqrt(n);
        cout << segSize << endl;
        int segs = (n + segSize - 1) / segSize;

        vector<int> segMaxis(segs, 0);
        for (int i = 0; i < n; i++) {
            segMaxis[i / segSize] = max(segMaxis[i / segSize], baskets[i]);
        }

        for (int qty : fruits) {
            bool placed = false;

            for (int i = 0; i < segs; i++) {
                if (segMaxis[i] >= qty) {

                    for (int j = i * segSize; j < min(n, (i + 1) * segSize);
                         j++) {
                        if (baskets[j] >= qty) {
                            baskets[j] = 0;

                            segMaxis[i] = 0;
                            for (int k = i * segSize;
                                 k < min(n, (i + 1) * segSize); k++) {
                                segMaxis[i] = max(segMaxis[i], baskets[k]);
                            }

                            placed = true;
                            break;
                        }
                    }
                }

                if (placed)
                    break;
            }

            if (!placed)
                cnt++;
        }

        return cnt;
    }
};
