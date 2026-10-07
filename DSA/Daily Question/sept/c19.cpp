// now i am doing the brace expansion 11
// under the grammar given below string can reperesetn a set of lowercase words
// let R(expr)denote the set of words the expession represents
// the grammar can best be understood through simple examples:
// single character: R(a) = {a}
// range of characters: R(a-z) = {a,b,c,...,z}
// When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
// R("{a,b,c}") = {"a","b","c"}
// R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
// When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
// R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
// R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
// Formally, the three rules for our grammar:

// For every lowercase letter x, we have R(x) = {x}.
// For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
// For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
// Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.
// now i have to understand the grammar and implement the solution in c++17
// when two same letter we have to take union of the two letters and return only one letter in the final answer
// approach we can use stack to store the characters and when we encounter a closing brace we can pop the elements from the stack and form the words and push it back to the stack
// for unique we can use set to store the words and finally return the sorted list of words
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip {

                set<string> inside = parse(s, i);

                // concatenation
                set<string> temp;
                for (auto &a : curr) {
                    for (auto &b : inside) {
                        temp.insert(a + b);
                    }
                }

                curr = temp;

                i++; // skip }

            } 
            else if (s[i] == ',') {
                // union
                for (auto &x : curr)
                    result.insert(x);

                curr.clear();
                curr.insert("");

                i++;
            } 
            else {
                // normal character
                char c = s[i];

                set<string> temp;

                for (auto &x : curr) {
                    temp.insert(x + c);
                }

                curr = temp;

                i++;
            }
        }

        // add final part
        for (auto &x : curr)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};