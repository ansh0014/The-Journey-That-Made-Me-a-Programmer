// now i am doing the number of string that appear as substrings in word
// i have given the string array patterns and the string word, return the number of strings in patterns that exist as a substring in word
// APPROACH: Iterate through each string in patterns and check if it exists as a substring in word
class Solution{
    public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        return count;
    }
};