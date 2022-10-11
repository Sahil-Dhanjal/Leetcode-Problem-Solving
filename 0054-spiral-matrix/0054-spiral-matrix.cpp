class Solution {
public:
    
    // Approach:
    // 1. Print the Starting Row [ then make the next row the "Starting row" ]
    // 2. Print the last Column [ then make the column one before it the "last column" ]
    // 3. Print the last row [ then make the row one before it the "last row" ]
    // 4. Print the Starting Column [ then make the next column the "Starting column"]
    
    // Printing + Simultaneous Updation of pointers for handling the consequent Traversals
    
    // Main thing is to handle the overlapping Numbers Case!
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // Answer Vector storing the traversal & the one that'll be returned finally.
        vector<int> ans;
        int mRows = matrix.size();
        int nCols = matrix[0].size(); // Any other vector could've been also taken since all the other vectors have the same number of columns to make a Square Matrix.
        
        int count = 0;
        int total = ( mRows * nCols );
        
        // Declaring & Initialising the pointers with their respective 'Indices'
        int startingRow = 0;
        int startingColumn = 0;
        int endingRow = mRows - 1;
        int endingColumn = nCols - 1;
        
        
        // Terminate once all the Elements have been traversed in the Spiral Order
        while( count < total ){
            
            // Printing the Starting Row
            // We're also mentioning the count < total  for our each printing case just so as to prevent the printing overlap 
            for( int index = startingColumn ; ( count < total && index <= endingColumn ) ; ++index ){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            
            // Update the starting Row Now to be worked on for the next iteration
            startingRow++;
            
            // Printing the Ending Column
            // We're also mentioning the count < total  for our each printing case just so as to prevent the printing overlap 
            for( int index = startingRow ; ( count < total && index <= endingRow ) ; ++index ){
                ans.push_back(matrix[index][endingColumn]);
                count++;
            }
            
            // Update the ending column Now to be worked on for the next iteration
            endingColumn--;

            // Printing the Ending Row 
            // We're also mentioning the count < total  for our each printing case just so as to prevent the printing overlap 
            for(int index = endingColumn ; ( count < total && index >= startingColumn ) ; --index){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            
            // Update the ending Row Now to be worked on for the next iteration
            endingRow--;
            
            // Printing the Starting Column
            // We're also mentioning the count < total  for our each printing case just so as to prevent the printing overlap 
            for( int index = endingRow ; ( count<total && index >= startingRow ) ; --index ){
                ans.push_back(matrix[index][startingColumn]);
                count++;
            }
            
            // Update the starting Column Now to be worked on for the next iteration
            startingColumn++;
        }
        
        return ans;
        
    }
};