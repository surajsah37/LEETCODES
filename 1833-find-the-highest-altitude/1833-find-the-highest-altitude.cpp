class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         int currentAltitude = 0; // Starting altitude
        int maxAltitude = 0;     // Track the highest point

        for (int g : gain) {
            currentAltitude += g; // Update current altitude
            maxAltitude = max(maxAltitude, currentAltitude); // Update max if needed
        }

        return maxAltitude; // Return the highest point reached
    }
};