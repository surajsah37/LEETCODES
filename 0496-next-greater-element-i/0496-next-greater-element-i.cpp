class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        // Loop through each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];       // Current number from nums1
            int nextGreater = -1;     // Initialize next greater as -1

            // Search for this number in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    // Once found, scan to the right to find next greater
                    for (int k = j + 1; k < nums2.size(); k++) { // FIXED: k < nums2.size()
                        if (nums2[k] > num) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break; // Exit after finding the element
                }
            }

            result.push_back(nextGreater); // Store result
        }

        return result; // FIXED: return was outside the function
    }
};
