class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
        
            // This And operation of 1 - 
            // 1. -> with 1 gives 1
            // 2. -> with 0 gives 0
            // In this manner i can extract original bits.
            // Moreover this just works on the MSB.
            // You don't need to worry about the other bits.
            if((n&1)){
                // We entered here only when the MSB was 1.
                // i.e. a Set bit.
                count++;
            }
        
            // Update before moving to the next iteration
            n = n>>1;
        }
        return count;
    }
};