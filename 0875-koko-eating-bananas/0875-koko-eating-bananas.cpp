class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hour = 0;

            for (int pile : piles) {
                hour += (pile + mid - 1) / mid; // correct hour calculation
            }

            if (hour <= h) {
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need faster speed
            }
        }
        return low;
    }
};
