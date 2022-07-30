class Solution {
    
private:
    
    // -> Binary to Decimal Conversion
    int toDecimal(int n){
        // We'll get some integer like 1110 in here.
        // It's not a binary representation for the compiler.
        // It is just an another regular integer for it & that's the way how it would treat it.
        
        int answer = 0;
        int bitPositionCounter = 0;
        
        while(n!=0){
            // Extract bits
            // The bit we've below is our current LSB.
            int bit = n%10;
            
            // Updating Answer
            answer += ( bit * pow(2, bitPositionCounter) );
                
            // Updating n & the counter Variable for the next Iteration
            n = n/10;
            bitPositionCounter++;
        }
        
        return answer;
    }
    
    // -> Decimal to Binary conversion 
    int toBinary(int n){
        
        int answer = 0;
        int bitPositionCounter = 0;
        
        while(n!=0){
            // Finding the LSB bit first
            int bit = n&1;
            
            // Updating the value of answer
            answer += (bit * pow(10, bitPositionCounter));
                
            // Updating the bitPositionCounter and the value of n before moving to the next iteration
            bitPositionCounter++;
            n = n>>1;
        }     
        
        return answer;  
    }
    
public:
    int bitwiseComplement(int n) {
        
        // Edge Case
        if(n == 0){
            return 1;
        }
        
        int m = n;
        int mask = 0;
        

        while(m!=0){
            
            // Left-shift Mask first by one and then take Mask's 'OR' operation with 1.
            mask = (mask<<1) | 1;
            
            // Updating 'm' before next iteration
            m = m>>1;
        }
        
        
        return (~n) & mask; 
    }
};