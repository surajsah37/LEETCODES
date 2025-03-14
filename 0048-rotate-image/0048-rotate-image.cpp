class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        
    int n=matrix.size();
    /*
    // transpose of the matrix
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);
    }
        // reverese of the matrix
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                start++,end--;
            }
        }
    }
    */
      // Step 1: Transpose the matrix (swap elements across the diagonal)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // Ensure swapping only in upper triangle
            swap(matrix[i][j], matrix[j][i]); // Swap elements to transpose
        }
    }

    // Step 2: Reverse each row to achieve 90-degree rotation
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end()); // Reverse each row
    }
}
};