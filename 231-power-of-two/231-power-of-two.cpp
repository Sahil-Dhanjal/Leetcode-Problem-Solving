class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        
        for(int i = 0 ; i <= 30 ; i++){
            // This loop executes 31 times
            
            if(n == ans){
                return true;
            }
            
            // Update Answer variable for the next iteration
            // But we've to pass the below 'IN-RANGE' Check
            if(ans <= INT_MAX/2){
                ans = ans*2;
            }
        }
        
        return false;
    }
};