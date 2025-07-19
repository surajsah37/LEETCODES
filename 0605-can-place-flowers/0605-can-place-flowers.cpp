class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();  // Get size of flowerbed
        if (n == 0)
            return true;  // If no flower to plant, always true

        for (int i = 0; i < l; i++) {
            if (flowerbed[i] == 0) {  // If current spot is empty
                // Check if left and right are also empty (or edge)
                bool left_khali = (i == 0) || (flowerbed[i - 1] == 0);
                bool right_khali = (i == l - 1) || (flowerbed[i + 1] == 0);

                if (left_khali && right_khali) {
                    flowerbed[i] = 1;  // Plant flower
                    n--;               // One less to plant

                    if (n == 0)
                        return true;   // Early return if all flowers planted
                }
            }
        }
        return false;  // Could not plant all required flowers
    }
};
