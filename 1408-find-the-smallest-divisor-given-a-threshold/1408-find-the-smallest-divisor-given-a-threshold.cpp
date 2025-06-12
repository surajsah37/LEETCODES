class Solution {
public:
int computeSum(vector<int>& nums, int divisor) {
    int sum = 0;  // Initialize sum
    for (int num : nums) {
        // Efficient way to calculate ceil(num / divisor) without using <cmath>
        sum += (num + divisor - 1) / divisor;
    }
    return sum;  // Return the total sum
}
    int smallestDivisor(vector<int>& nums, int threshold) {
          int left = 1;  // Smallest possible divisor
    int right = *max_element(nums.begin(), nums.end());  // Largest number in the array

    int answer = right;  // Initialize answer to the highest possible divisor

    // Binary search loop to find the minimum divisor
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle of the current range

        int currentSum = computeSum(nums, mid);  // Compute the sum using current mid as divisor

        if (currentSum <= threshold) {
            // If current sum is within the threshold, mid is a valid divisor
            answer = mid;        // Store current mid as a potential answer
            right = mid - 1;     // Try to find a smaller valid divisor
        } else {
            // If current sum is greater than threshold
            left = mid + 1;      // Need a bigger divisor to reduce the sum
        }
    }

    return answer;  // Return the smallest valid divisor found
}
};