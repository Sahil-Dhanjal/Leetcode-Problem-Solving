class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // First Adding one to the last index element
        int lastIndex = digits.size() - 1;
        
        // Finding carry & replacing the last digit with the unit place of the number found after addition.
        int sum = digits[lastIndex] + 1;
        int carry = (sum)/10;
        digits[lastIndex] = sum%10;
        
        // If the carry was zero
        if(carry == 0){
            return digits;
        }
        
        // If the carry was non-zero, operate on addition until the carry is non-zero
        // We'll start from the index before the last index as the last index has been already dealt with.
        int index = lastIndex - 1;
        while( (index >= 0) && (carry > 0) ){
            int sum = digits[index] + carry;
            carry = (sum)/10;
            digits[index] = sum%10;
            index--;
        }
        
        // If the carry is still Non-zero & the index has reached the very first index in our digits vector i.e. 0
        // It means that we now-need to make space for one carry digit in the digits vector
        // We will shift every element by one place in the digits vector
        if(carry!=0){
            digits.push_back( digits[digits.size()-1] );
            index = digits.size() - 2;
        
            while(index>=0){
                digits[index+1] = digits[index];
                index--;
            }
        
            // Putting that carry digit in the first index in the new shifted digits vector
            digits[0] = carry;
        }

        
        // Returning digits vector.
        return digits;        
    }
};