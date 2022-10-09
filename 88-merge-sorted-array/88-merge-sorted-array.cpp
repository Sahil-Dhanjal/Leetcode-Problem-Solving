class Solution {
public:
    
// SOLUTION 01
// 1. We took j = 0 to iterate nums2 from the beginning.
// 2. As we know nums1 has a size of m+n & only first m elements should be in the final array.
// 3. So we replace all the elements from m index with all the elements of nums2.
// 4. Finally, we’ll sort the array nums1 to get the final sorted array.
// Time complexity: O(nlogn) //as sorting takes nlogn time.
    
// Solution 02 [Optimized to the Previous Solution]
// 1. As both solutions 01 & 02 takes O(nlogn), now we try to solve it with O(n+m).
// 2. We will use the reverse sorting method.
// 3. We took 3 variables: i (last valid element of nums1 that will present in final array), j (last element of nums2) & k ( last index of nums1)
// 4. First, while loop will compare nums1 & nums2 and the greater element will be in nums1[k].
// 5. After the loop end if there is still any elements left in any array that will be added by next 2 while loop.
// Time complexity: O(m+n).
    
// AN ANOTHER APPROACH
// 1. Make a New vector nums with size (n+m)
// 2. if there were no elements in nums2, simply return as there's nothing to do to nums1
// 3. Otherwise, while both the pointers are withing their limits
// 4. We merge sort exactly how we conventionaly do [like inserting the sorted elements into the third vector]
// 5, Finally, copy the elements from nums vector to the nums1 vector and return.
// Time Complexity: O(m+n) but Space Complexity -> O(m+n)
    
// WE'LL BE USING THE REVERSE SORTING METHOD.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // i pointer is for Nums1 [end of the current elements present in it]
        int i = m-1;
        
        // j pointer is for Nums2
        int j = n-1;
        
        // k pointer is for Nums1 [it ends at the very last index of the overall Nums1 Array]
        int k = (m + n) -1;
        
        while(i>=0 && j>=0){
            if( nums1[i] > nums2[j] ){
                
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        
        // Dealing with the remaining elements now
        while( i >= 0 ){
           nums1[k] = nums1[i];
            k--;
            i--;
        }
        
        while( j >= 0 ){
            nums1[k] =nums2[j];
            k--;
            j--;
        }
    }
};