class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
         int maxOnes = -1;
    int rowIndex = -1;
    
    for (int i = 0; i < mat.size(); i++) {
        int countOnes = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) countOnes++;
        }
        
        if (countOnes > maxOnes) {
            maxOnes = countOnes;
            rowIndex = i;
        }
    }
    
    return {rowIndex, maxOnes};
    }
};