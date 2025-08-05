class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int n = fruits.size();
    vector<bool> used(n, false);  // to mark used baskets
    int unplaced = 0;

    for (int i = 0; i < n; i++) {
        bool placed = false;
        for (int j = 0; j < n; j++) {
            if (!used[j] && baskets[j] >= fruits[i]) {
                used[j] = true;  // mark basket as used
                placed = true;
                break;
            }
        }
        if (!placed) unplaced++;  // could not place this fruit
    }

    return unplaced;

    }
};