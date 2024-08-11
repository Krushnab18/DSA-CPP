class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Handle edge case for empty input
        
        string prefix = strs[0]; // Start with the prefix as the first string
        
        for (int i = 1; i < strs.size(); i++) {
            // Update prefix by comparing with each string in the vector
            while (strs[i].find(prefix) != 0) { // If current string does not start with the prefix
                prefix = prefix.substr(0, prefix.length() - 1); // Reduce the prefix
                if (prefix.empty()) return ""; // If no common prefix exists
            }
        }
        
        return prefix;
   // }
};

