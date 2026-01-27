class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int requireday = 1;
            int currload = 0;

            for (int w : weights) {
                if (currload + w <= mid) {
                    currload += w;
                } else {
                    requireday++;
                    currload = w;
                }
            }

            if (requireday <= days) {
                ans = mid;
                high = mid - 1;   // try smaller capacity
            } else {
                low = mid + 1;    // need more capacity
            }
        }

        return ans;
    }
};
