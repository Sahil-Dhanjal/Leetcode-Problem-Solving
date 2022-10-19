class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // Base cases
        if(strs.size() == 0){
            return "";
        }
        
        if(strs.size() == 1){
            return strs[0];
        }
        
        // Sort the Given Vector of Strings so that all the strings get arrangesd in a lexicographically increasing order.
        // The ones that come in the dictionary first would appear first & the ones that come later would appear later.
        // Now since we need only the prefix of the strings, we would check & compare only the first and the last string in the sorted vector of strings. If their prefixes don't match, we return an empty string, otherwise we keep adding their prefixes into our 'ans' string until a mismatch isn't found.
        sort(strs.begin() , strs.end());
        
        string ans;
        
        // After sorting - first and last strings in our input vector
        string a = strs[ 0 ];
        string b = strs[ strs.size() - 1 ];
        
        // Since the vector of strings is now sorted - lexicographically, therefore even the strings that'll be shorter [lexicographically] would appear earlier. Because of this, we iterate only till the length of the first string i.e. 'a' is not traversed entirely in our quest for finding the longest common prefix.
        for(int i = 0; i<a.size(); i++){
            if(a[i] == b[i]){
                // Matching Initial Characters Case
                // Add the character to our ans vector & then Move forward.
                ans+=a[i];
            }else{
                // Unmatching Initial Characters Case
                // Move out - break
                break;
            }
        }
        
        return ans;
        
    }
};