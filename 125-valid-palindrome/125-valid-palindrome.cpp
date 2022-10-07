class Solution {
    
private:
    // Checks if the character is a valid character [i.e. - Is it Alphanumeric]
    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return 1;
        else return 0;
    }
    
    // Converting the Passed Valid Character to its corresponding Lowercase character           
    char toLowerCase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) return ch;
        else{
            return ((ch - 'A') + 'a');
        }
    }
           
    // We call this after the string has been very much filtered out
    bool checkPalindrome(string s){
        int start = 0;
        int end = (s.size()-1);
        
        while(start<end){
            if(s[start] != s[end]){
                return 0;
            }else{
                start++;
                end--;
            }
        }
        // If we reach here outside this just shows that we never encountered the first condition & hence  the entire string traversal was complete. Voila! The string is a Palindrome!
        return 1;
    }
           
public:
    
    bool isPalindrome(string s) {
        
        string temp = "";
        
        // Inserting all the Valid characters into our "temp" string that we'll be working on
        for(int j = 0; j<s.size(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
                
        // Now converting all the valid characters [Alpha-numeric] into Lowercase Letters
        for(int j = 0; j < temp.size(); j++){
            temp[j] = toLowerCase(temp[j]);
        }

        // By now, we've with us a filtered out temp string
        return checkPalindrome(temp);
    }
};