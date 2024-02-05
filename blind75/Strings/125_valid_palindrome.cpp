
// Link: https://leetcode.com/problems/valid-palindrome/description/
/* Description:

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/

class Solution {
public:
    bool isPalindrome(string s) {
        /*
        vector<char> vt;
        for(int i=0; i<s.size(); i++){
            if( isalnum( s[i] ) ){
                /*if(s[i] >= 65 and s[i] <= 90){
                    vt.push_back(s[i]-65+97);
                    continue;
                }
                vt.push_back(tolower(s[i]));
            }
        } */
        /*
        while(!vt.empty()){
            if(vt[vt.size()-1] == vt[0]){
                if(vt.size()==1){
                    return true;
                }
                vt.pop_back();
                vt.erase(vt.begin());
            } else {
                cout << "front : "<<vt[0] << " Back : "<<vt[vt.size()-1];
                return false;
            }
        } */
        int front = 0;
        int back = s.size()-1;
        for(int i=0; i<s.size(); i++){
            while(!isalnum(s[front])){
                front++;
            }
            while(!isalnum(s[back])){
                back--;
            }
            if(front>=back){
                return true;
            }
            if(tolower(s[front++])!=tolower(s[back--])){
                cout << s <<".    ";
                cout << "front : "<<s[front-1] << " Back : "<<s[back+1];
                return false;
            }
        }
        return true;
    }
};

