class Solution {
public:
    int hIndex(vector<int>& citations) {
         // Sort citations in descending order
    sort(citations.rbegin(), citations.rend());
    
    int h = 0; // Initialize h-index
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) { // If citations count is at least i+1
            h = i + 1; // Update h-index
        } else {
            break; // Stop when condition is not met
        }
    }
    return h; // Return final h-index

    }
};