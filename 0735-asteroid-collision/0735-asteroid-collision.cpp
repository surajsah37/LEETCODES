class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;

        for (int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];  // Get the current asteroid
            bool isDestroyed = false;    // Check if it will be destroyed

            // Check collision only if current is going left and stack top is going right
            while (!result.empty() && current < 0 && result.back() > 0) {
                if (abs(current) > abs(result.back())) {
                    result.pop_back(); // Top asteroid is destroyed
                    // Keep checking with next top
                }
                else if (abs(current) == abs(result.back())) {
                    result.pop_back(); // Both destroyed
                    isDestroyed = true;
                    break;
                }
                else {
                    // Current asteroid is destroyed
                    isDestroyed = true;
                    break;
                }
            }

            // If it survives all collisions, add to result
            if (!isDestroyed) {
                result.push_back(current);
            }
        }

        return result;
    }
};
