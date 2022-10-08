class Solution {
public:

    // FIRST Approach -> Took O(m) Space Complexity & O(n) space complexity
    // m -> the number of words a String has
    // n -> Total Characters in a String
    // My first Approach included storing each word in a Vector of Strings 
    // And then Printing the words in the vector from the last index appending a Space after every word to get the result output.
    // Approach is fine but the Memory limit Exceeded.
    
//     string reverseStringOfWords(vector<string> answer){
//         // Reversed String of Words 'Ans'
//         string ans;

//         // We start from the Vector of Strings Last index And work till its First index
//         int i = answer.size() - 1;

//         while(i>=0){
//             cout<<answer[i]<<answer[i].size()<<endl;
//             ans.append(answer[i]);
//             if(i!=0){
//                 // Don't append a Space for the 0th string sicne it'll be the last word in reversed O/P [And if appended it'll add a Trailing Space to our Result which is Unacceptable].
//                 ans.push_back(' ');
//             }

//             i--;
//         }

//         return ans;
//     }
    
//     string reverseWords(string input) {
        
//         int index = 0;    
//         vector<string> answer;
        
//         // Work until a NULL Character isn't encountered
//         while(input[index]!='\0'){
            
//             // Potential Leading spaces in the beginning case [move to a Non-Space Character first ]
//             if(input[index]==' '){
//                 while( index != '\0' && input[index] == ' ' ){
//                     index++;
//                 }
//             }

//             // We could've been out due to two reasons
//                 // 1. Null character was encountered as we've reached the end of the given input string
//                 // 2. We encountered a Non-Space Character
//             if(input[index]=='\0'){
//         	    break;
// 		    }else{
// 			    // There on our first Non-Space character currently
// 	            // Process it & Store it Simultaneously.
// 	            string s;
//                 while( index<input.length() && input[index]!=' ' ){
//                     s.push_back(input[index]);
//                     cout<<s<<s.size()<<endl;
//                     index++;
//                 }
 
//                 // Here, means that we completely processed the Previous String            
//                 // Therefore, store our Previously processed String in the Answer Vector
//                 answer.push_back(s);	
// 		    }
            
//         }
        
//         // Reverse our String of Stored Words and Reverse the Answer
//         return reverseStringOfWords(answer);
//     }
    
void reverseString(string &input , int start , int end ){         
    while(start < end){
            
        swap( input[start] , input[end] );
        
        start++;
        end--;
            
    }
	
	// cout<<endl<<input<<endl;     
}
    
string reverseWords(string input) {
        
    // Reverse the input String first
    reverseString(input, 0, input.length() - 1);
        
    // Now reverse Every Word in the input String
    // Traversing the String
    int index = 0;
    while( index < input.length() ){
        // cout<<"\n1Current Character-> "<<index<<":"<<input[index];
        // Dealing with both the Leading & Trailing Zeros
        if( ( index<input.length() ) && ( input[index]== ' ' ) ){
                
            while( index < input.size() && input[index] == ' ' ){
            	// cout<<"\n2Current Character-> "<<index<<":"<<input[index];
                // If the next character is a Non-Space Character
                if( ( (index + 1) < input.length() ) && ( input[index+1] != ' ' ) ){
                        
                    // Then, in this case, we'll be leaving the Space as it is
                    // Now move to that next character
                    index++;
                        
                }else if ( ( (index + 1) < input.length() ) && ( input[index+1] == ' ' ) ){
                    // The next character is a space character - erase it & then don't move to the following character because after removing the space, the erase function is still going to keep you on the current index - so work on it from  this place's perspective
                    input.erase( index , 1 );
                    // cout<<"\nInputSize -> "<<input.size()<<endl;
                }else{
                	// This is the case where we reached the last character and it's a space character itself.
                	// Due to this we would be stuck in an infinite loop due to the conditions written above.
                	// In order to get out of it, we'll be using a break Statement.
                	break;
				}
                    
            }
    	}
            
        if(index == input.length() - 1 ){
        	break;
		}
		
        // Now, we're currently at a Non-Space Character
        // Traverse the String to get its ends so that we can reverse it
        int start = index;
        int end = start;
        while( ( index<input.length() ) && ( input[index]!= ' ' ) ){
        	// cout<<"\n3Current Character-> "<<index<<":"<<input[index];
            index++; 
            end++;
        }
            
        // here the end pointer would be one more place ahead of the String's Actual End
        // Therefore, we pass end-1 here.
        reverseString( input , start , end-1 );
	}
        
        // Removing the Space from the Start & the end [if they existed!]
        if(input[0] == ' '){
            input.erase(0,1);
        }
            
        if(input[ (input.length() - 1) ] == ' ') {
            input.erase( (input.length() - 1) , 1);
        }
            
        return input; 
}    
};