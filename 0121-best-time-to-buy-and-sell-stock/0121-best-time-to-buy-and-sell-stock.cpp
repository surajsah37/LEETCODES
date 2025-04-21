class Solution {
public:
   int maxProfit(vector<int>& prices) {

  int minPrice = prices[0];  // \U0001f7e2 Step 1: Assume the first day's price is the minimum price
    int maxProfit = 0;         // \U0001f7e2 Step 2: Initialize max profit as 0

    // \U0001f501 Step 3: Traverse the price array from day 1 to the end
    for (int i = 1; i < prices.size(); i++) {
        // \U0001f50d Step 4: If we find a lower price, update minPrice
        if (prices[i] < minPrice) {
            minPrice = prices[i];  // Update buying price
        }
        // \U0001f4b0 Step 5: Check profit if we sell at today's price
        else {
            int profit = prices[i] - minPrice;  // Calculate profit
            if (profit > maxProfit) {
                maxProfit = profit;  // Update maxProfit if it's higher than before
            }
        }
    }

    return maxProfit;  // ✅ Return the maximum profit found
}
};

//          int l = 0;           // Left pointer (buy day)
//     int r = 0;           // Right pointer (sell day)
//     int maxprofit = 0;   // Variable to store the maximum profit

//     // Traverse the array using the right pointer
//     while (r < prices.size()) {
//         if (prices[l] < prices[r]) { // If buying at l and selling at r is profitable
//             int profit = prices[r] - prices[l]; // Calculate the profit
//             maxprofit = max(maxprofit, profit); // Update the maximum profit
//         } 
//         else { 
//             l = r; // If prices[r] is lower, update l to r (new buying opportunity)
//         }
//         r++; // Move the right pointer forward
//     }

//     return maxprofit; // Return the maximum profit found
// }