class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // Vector storing our answers
        vector<int> ans;
        
        // Traversing the complete Array
        for(int i = 0; i<nums.size(); i++){
            
            // The current element we've in hand.
            int element = abs(nums[i]);
            
            // Has the mapping ever been done previously.
            if(nums[element-1] < 0){
                // If the mapping says that the element is smaller than o
                // This shows that the element has been already covered once  since we made its mapping to index-1 position by ourselves
                ans.push_back(element);
            }else{
                nums[element-1] = -1 * nums[element-1];
            }
        }
        
        return ans;
    }
};