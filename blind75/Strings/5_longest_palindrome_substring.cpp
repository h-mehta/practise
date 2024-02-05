
// Link: https://leetcode.com/problems/longest-palindromic-substring/description/
// Description:
/*

5. Longest Palindrome substring

Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        bool **dp = new bool*[n];
        for(int i=0; i<n; i++){
            dp[i] = new bool[n];
            memset(dp[i], false, n*sizeof(bool));
            dp[i][i] = true;
            ans = s[i];
        }

        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                ans = s.substr(i, 2);
            } else {
                dp[i][i+1] = false;
            }
        }

        for(int diff= 2; diff<n; diff++){
            for(int i=0; i<n-diff; i++){
                int j= i+diff;
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans = s.substr(i, diff+1);
                }
            }
        }
        return ans;
    }
};


/* Complexity:

Time: O(n^2)
Space: O(n^2)

*/
