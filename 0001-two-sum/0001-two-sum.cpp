class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          unordered_map<int, int> seen;  // stores number and its index

    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int needed = target - current;  // what number we are looking for

        // check if needed number is already in the map
        if (seen.find(needed) != seen.end()) {
            return {seen[needed], i};  // return indices
        }

        // store the current number with its index
        seen[current] = i;
    }

    return {}; // just in case, though question says one solution always exists
}
};