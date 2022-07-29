class Solution {
public:
    int reverse(int x) {
        
        int answer = 0;
        
        while(x!=0){
            int digit = x%10;
            
            if((answer > INT_MAX/10) || (answer < INT_MIN/10)){
                // Answer ko update karne se pehle hi & range se bahar jaane se pehle hi
                // We place a check on the state just one before the erroneous State
                return 0;
            }
            
            // Update krdo bhaiya
            // Hamme assurity hai ki hamra Answer abhi range se bahar nahi jayega
            // Max to Max hamara answer INT_MIN ya INT_MAX ke daswein hisse se hi bada ya chota ho sakta hai respectively.
            answer = (answer*10) + digit;
            x = x/10;
        }
            
        return answer;
    }
};