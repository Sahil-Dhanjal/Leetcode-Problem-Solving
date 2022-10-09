class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // Rather than looking at this like moving all the Zeros to the right.
        // We'll be moving all the Non-zeros to the left.
        
        // This pointer represents the Index Available for the correct Placement of any Non-Zero Number encountered while we were traversing the Array.
        int nonZero = 0;
        
        // In case of Such an encounter, we swap the values.
        // Then, Increment the nonZero Pointer to make space for the next non-zero encounter.
        
        // Traversing the Array.
        for( int j = 0 ; j < nums.size() ; j++ ){
            // If the current element would've been a Non-zero Number - Swap
            if(nums[j]!=0){
                
                // Swapping
                swap( nums[j] , nums[nonZero]);
                
                // Post - Swapping , increment the Non-Zeor Pointer to make space for the Next non-zero encounter.
                nonZero++;
            }
        }
    }
};