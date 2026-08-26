// now i am doing the weekly contest 516
// problem 1: 
// now we are doing the check ASCII Palindrome
// WE have givne string s consisting of lowercase English letters. We need to determine whether it is possible to make the string a palindrome by changing at most one character.
// we used two pointer approach to check the palindrome and then used the condition to check the change
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string s) {

        string binary = "";

        for (char ch : s) {

            int ascii = ch;

            for (int i = 7; i >= 0; i--) {

                if (ascii & (1 << i)) {
                    binary += '1';
                }
                else {
                    binary += '0';
                }
            }
        }

        int left = 0;
        int right = binary.size() - 1;

        while (left < right) {

            if (binary[left] != binary[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
