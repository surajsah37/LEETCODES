class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int l = 0;           // Left pointer (buy day)
    int r = 0;           // Right pointer (sell day)
    int maxprofit = 0;   // Variable to store the maximum profit

    // Traverse the array using the right pointer
    while (r < prices.size()) {
        if (prices[l] < prices[r]) { // If buying at l and selling at r is profitable
            int profit = prices[r] - prices[l]; // Calculate the profit
            maxprofit = max(maxprofit, profit); // Update the maximum profit
        } 
        else { 
            l = r; // If prices[r] is lower, update l to r (new buying opportunity)
        }
        r++; // Move the right pointer forward
    }

    return maxprofit; // Return the maximum profit found
}

};