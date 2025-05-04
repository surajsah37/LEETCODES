class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;         // Stores indices of useful elements in decreasing order
        vector<int> res;       // Stores the max of each window

        // Process first k elements (initial window)
        for (int i = 0; i < k; i++) {
            // Remove all smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process the rest of the elements
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]); // Front of deque is max of last window

            // Remove indices out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than current from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i); // Add current index
        }

        // Add max of last window
        res.push_back(nums[dq.front()]);

        return res; // ✅ Missing in your code
    }
};