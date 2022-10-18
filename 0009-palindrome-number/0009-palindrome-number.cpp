class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0){
            return false;
        }
        
        vector<int> number;
        
        while(x!=0){
            number.push_back(x%10);
            x = x/10;
        }
        
        int start = 0;
        int end = number.size() - 1;
        while(start < end){
            if(number[start++]!=number[end--]){
                return false;
            }
        }
        
        return true;
    }
};