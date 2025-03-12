class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int maxprofit = 0; // Initialize the total profit to 0

    // Traverse the prices array from the second day onward
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) { // If the current price is higher than the previous price
            maxprofit += prices[i] - prices[i - 1]; // Add the profit from this transaction
        }
    }

    return maxprofit; // Return the total maximum profit

    }
};