class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for the last element in nums1 (excluding extra space)
    int j = n - 1;         // Pointer for the last element in nums2
    int k = m + n - 1;     // Pointer for the last position in nums1

    // Merge from the end to avoid overwriting elements in nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];  // Place the larger element at the end
        } else {
            nums1[k--] = nums2[j--];  // Place the larger element at the end
        }
    }
 //if elements are left in nums2, copy them (nums1 is already sorted)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
       }
    
    }
};