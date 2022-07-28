class Solution {
public:
    int subtractProductAndSum(int n) {
        int product;
        int sum = 0;
    
        // Dono ko we'll handle saath mein, so that we just traverse once.
        if(n == 0){
            product = 0;
        }else{
            product = 1;
        }
    
        while(n!=0){
            int currentDigit = n%10;
            n = n/10;     
            sum += currentDigit;
            product *= currentDigit;
        }
    
        return (product - sum);
    }
};