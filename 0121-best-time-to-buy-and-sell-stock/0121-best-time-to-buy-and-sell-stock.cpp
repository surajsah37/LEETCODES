class Solution {
public:
   int maxProfit(vector<int>& prices) {
  int minPrice = prices[0];  // \U0001f7e2 Step 1: Assume the first day's price is the minimumprice
    int maxProfit = 0;         // \U0001f7e2 Step 2: Initialize max profit as 0
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
    return maxProfit; }
};