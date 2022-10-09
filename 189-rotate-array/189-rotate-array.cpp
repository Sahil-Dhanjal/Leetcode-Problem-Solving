class Solution {
public:
    
// //    THE NON-INPLACE WAY OF SOLVING & USING AN ADDITIONAL MEMORY SPACE OF O(n) [BRUTE - FORCE SOLUTION]
//     void rotate(vector<int>& nums, int k) {
//         // temp vector [has the Rotated elements] for new element position from the nums vector
//         // Made solely to prevent the Overwriting in the case when only nums vector would've been taken and operated on
//         // [overwriting at the time when the elements from the beginning are placed at their new positions in the same vector 'nums']
    
//         int n = nums.size();
//         vector<int> temp( n );
        
//         // Traversing the nums vector & then placing the elements at their new positions in the temps vector [has the rotated elements].
//         for( int i = 0 ; i < nums.size(); i++){
//             int newPosition = (i + k) % n;
//             temp[newPosition] = nums[i];
//         }
        
//         // Finally, copy the elements from the temp vector [ that has the array nums's rotated elements]
//         for( int i = 0 ; i < temp.size() ; i++ ){
//             nums[i] = temp[i];
//         }
//     }
    
    // ----------------------------------------------------------
    
    // THIS BELOW SOLUTION IS AN INPLACE SOLUTION
    
    void reverse( vector<int> &nums, int start, int end){
        
        while( start < end ){
            swap ( nums[ start++ ] , nums[ end-- ] );
        }
        
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // 1. Determining The Actual net rotations to be made
        if( k < 0 ){
            k = k  + n;
        }
        
        k = k % n;
        
        // 2. Divide the Array into two parts & reverse them individually!
        reverse( nums , 0 , n - k - 1 );
        reverse( nums , n - k , n - 1 );
        
        // 3. Reverse the Total Array
        reverse( nums , 0 , n - 1 ); 
        
    }
};
