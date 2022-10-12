class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Matrix Dimensions
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Start from the Top right most corner element in our 2D Matrix
        int rowIndex = 0;
        int colIndex = cols-1;
        
        // We work until the rowIndex & colIndex for our current Element Stay in Bounds!
        while( (rowIndex < rows) && (colIndex >= 0) ){
            int currentElement = matrix[rowIndex][colIndex];
            // Running the following cases to know which direction to move further into.
            if( target == currentElement ){
                // Voila! Element Found.
                return true;
            }else if( target > currentElement ){
                // We'll move in the vertical direction as the elements within the same column as our Current Element are going to be greater than it & therfore the chances of finding the target in this direction [vertical - moving within the same column] are going to be very high.
                rowIndex++;
            }else if( target < currentElement ){
                // We'll move in the horizontal direction as the elements within the same row as our Current Element are going to be smaller than it & therfore the chances of finding the target in this direction [horizontal - moving within the same row] are going to be very high.
                colIndex--;
            }
        }
        
        // Here, therefore it means that the 'return 1' statement was never encountered
        // Which means that the Element is not present in our Matrix
        
        return 0;
    }
};