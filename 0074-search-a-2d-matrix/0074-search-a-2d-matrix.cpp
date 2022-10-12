class Solution {
public:
    
    // Applying Binary Search in a 2D Matrix
    // We visualise our 2D Array as a Linear One
    // And the resulting linear Array would be entirely sorted due to the property of the matrix given.
    // We'll use this sorted values property of the elements in the Linear Array to 'binary search' the target value in it.
    
    // The Main work that's to be done in this problem is just to determine how we map that 'mid' value to the correct element in the given 2D Array.
    // Mapping is done since, the 1D Array thingie is just our visualisation but everything has to be actually implemented on the 2D Array in a Efficient way I.e. using binary search the time complexity gets down to O(log(m*n))
    
    // A BRUTE FORCE We could've also done is to first copy all the elements from the 2D Array to a linear Array row-by-row One by one.
    // But since this would've taken a Time complexity of O(m*n) to just copy elements - THIS ISN'T GOING TO BE EFFICIENT FOR THE SERCHING PURPOSES.
    
    // Therefore, WE'LL SOLVE IT IN-PLACE.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Matrix Dimensions
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0;
        int end = (rows*cols) - 1;
        
        // Starting the binary search
        while(start<=end){
            
            // Finding the Middle element
            int mid = (start + end) /2;
            
            // Finding the coresponding row and column indices of the Middle Element in the 2D Array [READ NOTES TO UNDERSTAND THIS]
            int rowIndex = mid / cols;
            int colIndex = mid % cols;
            
            // Checking for the following cases to down-size the Array to work on And the Array to ignore
            if( matrix[rowIndex][colIndex] == target ){
                // Voila! Found.
                return true;
            }else if( matrix[rowIndex][colIndex] > target ){
                // Down-Sizing for the next Iteration
                // Target would be found in the left Sub-Array to mid.
                // Therefore,
                end = mid - 1;
                
            }else if( matrix[rowIndex][colIndex] < target ){
                // Down-sizing for the next Iteration
                // Target would be found in the right Sub-Array to mid.
                // Therefore,
                start = mid + 1;
            }
            
        }
        
        // Here, means that 'return 1' was never encountered
        // Therefore, 'return 0' as the target couldn't be found
        return 0;
    }
};