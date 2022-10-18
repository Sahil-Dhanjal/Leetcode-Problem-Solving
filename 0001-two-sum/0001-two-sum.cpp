class Solution {
public:
    
    // APPROACH - 1
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> answer;
        
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i + 1; j < nums.size(); j++){
//                 if(nums[i]+nums[j] == target){
//                     answer.push_back(i);
//                     answer.push_back(j);
//                     break;
//                 }
//             }
//         }
        
//         return answer;
//     }
    
    // APPROACH - 2
    vector<int> twoSum(vector<int>& nums, int target) {
        // We're going to store the Vector's element and it's corresponding Index in the map.
        unordered_map<int,int> mp;
        
        // Inserting all the elements of the given vector into the Unordered map & side by side finding the another element to complete the pair
        // O(n)
        for(int i = 0; i < nums.size(); ++i){
            // first check - is the another element present in the map to complete the target sum
            int currentElement = nums[i];
            int remainingTargetSumRequired = target - currentElement;
            
            if(mp.find(remainingTargetSumRequired) != mp.end()){
                // return the current Element's index & the index of the element thaht completed the remaining sum.
                return { i , mp[remainingTargetSumRequired] };
            } 
            
            // If not found - no problem!
            // Simply move ahead but before that do insert the proper mapping in the Unordered map.
            // This could've been also done before the 'if part' as well but we didn't as this could've made us run into the same element forming the tsarget sum case!
            mp[currentElement] = i;
        }

        
        // Returning an empty vector as the Sum was not found.
        return {};
    }
};