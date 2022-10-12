class Solution {
public:
    
    void transpose(vector<vector<int>>& matrix){
        
        // A matrix can be converted into its Transpose by either:
        //   1. Converting all the rows into columns
        //   2. or, Columns into Rows
        
        // Transpose matrix has
        // A'[i,j] = A[j,i] (of the given matrix) -> we'll be using this property.
        
        // Here, i'm converting the rows into columns
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int row = 0; row <= ( rows - 2 ); row++ ){
            for(int col = 1 + row; col <= ( cols - 1 ); col++ ){
                swap(matrix[row][col] , matrix[col][row]);
            }
        }
        
    }
    
    void reverseRow(vector<vector<int>>& matrix , int rowIndex){
        
        int cols = matrix[0].size();
        
        int start = 0;
        int end = cols - 1;
        
        while(start < end){
            swap(matrix[rowIndex][start] , matrix[rowIndex][end]);
            start++;
            end--;
        }
    }
    
    
    void rotate(vector<vector<int>>& matrix) {
        
        // Step 1: Find the Transpose of the Matrix first.
        transpose(matrix);
        
        // Step 2: Reverse every row of this Transposed Matrix
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int row = 0; row <= (rows - 1); row++ ){
            reverseRow( matrix , row );
        }

        }
};
