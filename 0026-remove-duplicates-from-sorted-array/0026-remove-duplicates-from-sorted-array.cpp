class Solution {
public:
    
    // We're going to solve this question by using the TWO-POINTER APPROACH.
    int removeDuplicates(vector<int>& nums) {
        
        // Base case
        if(nums.size() == 1){
            return 1;
        }
        
        // Traversing the vector now & doing the operations
        int index = 0;
        
        // Initialising the Two Pointers that'll be used for In-place doing the work
        int left = 0;
        
        // We'll start the right pointer from the index next to the left pointer (i.e. 1)
        // Until, we haven't entirely traversed the array
        for(int right = 1; right < nums.size(); right++ ){
            // If the elements are not similar
            // increment left
            // And then swap the elements present at this incremented left position & right position
            // Since the current tight position element is already dealt with - we will be incrementing right in both the cases
            if(nums[left]!=nums[right]){
                left++;
                swap( nums[left] , nums[right] );
            }
            // Otherwise, we'll simply increment right - which the loop's counter variable would Automatically do!
        }
        
        // left is going to be present at the most recent unique element that it foun in the Array
        // therefore, in total there are (left+1) unique elements in our nums vector
        return left + 1;
    }
};