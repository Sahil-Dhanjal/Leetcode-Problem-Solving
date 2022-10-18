class Solution {
public:
    
    // Approach 1: Store all the digits in a vector and use the two pointer approach (start < end) to check if the digits match from either side.
    // Uses O(n) extra space.
//     bool isPalindrome(int x) {
        
//         if(x < 0){
//             return false;
//         }
        
//         vector<int> number;
        
//         while(x!=0){
//             number.push_back(x%10);
//             x = x/10;
//         }
        
//         int start = 0;
//         int end = number.size() - 1;
//         while(start < end){
//             if(number[start++]!=number[end--]){
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
    // Approach 2: Reverse the given integer and then compare it to its reverse. If they're equal therefore the given integer was a palindrome, otherwise not.
    // Approach 2 uses no extra space while approach 1 does.
    int reverse(int x){
        
        // Declared long long int to prevent the case of integer overflow.
        long long int rev = 0;
        
        while(x!=0){
            // get the last digit
            int last = x%10;
            
            // Add it to the integer rev so that the digit comes to the front
            rev = ( (rev*10) + last);
            
            // Cut down given integer's size to move to its next unit integer
            x = x /10;
        }
        
        return rev;
    }
    
    bool isPalindrome(int x) {
        
        
        if(x < 0){
            // Because of the Assumption that the negative numbers are non-palindromic
            return false;
        }
        
        int rev = reverse(x);
        
        if(rev == x){
            return true;
        }else{
            return false;
        }
    }
};