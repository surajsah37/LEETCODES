class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Initialize total gas and total cost to 0
        int totalGas = 0, totalCost = 0;

        // 'tank' keeps track of gas in car during the journey
        // 'start' is the index of the gas station where we start
        int tank = 0, start = 0;

        // Loop through all gas stations
        for (int i = 0; i < gas.size(); i++) {
            // Add current station's gas to totalGas
            totalGas += gas[i];

            // Add current station's cost to totalCost
            totalCost += cost[i];

            // Add net gain/loss of gas at this station to the tank
            tank += gas[i] - cost[i];

            // If tank is negative, it means we can't reach the next station
            if (tank < 0) {
                // So, set the next station as a new starting point
                start = i + 1;

                // Reset tank to 0 since we're starting fresh
                tank = 0;
            }
        }

        // If total gas is less than total cost, return -1 (not possible to complete circuit)
        // Otherwise, return the starting index
        return (totalGas < totalCost) ? -1 : start;
    }
};
