class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int requiredDays = 1;
            int currentLoad = 0;
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    requiredDays++;
                    currentLoad = 0;
                }
                currentLoad += w;   }
            if (requiredDays <= days) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            } }
        return result;
    }
};
