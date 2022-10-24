class Solution {
public:
    int lengthOfLastWord(string s) {
        // We start from the rear end of the Given String
        int index = s.size() - 1;
        
        // Dealing with the Whitespaces first that might would've been present in the rear end of the string first
        while(index >= 0 && s[index] == ' '){
            index--;
        }
        
        // Here, the index is going to be present at a non-whitespace character
        // We start with our character counting character now
        // The character count operation would keep on working until an another Whitespace character is encountered [which is going to be present before the starting character of the last word]
        int count = 0;
        while(index >= 0 && s[index] != ' '){
            count++;
            index--;
        }
        
        return count;
    }
};