
/*

Link: https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

2390. Removing stars from a string

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

*/


class Solution {
public:
    string removeStars(string s) {
        stack<char> ans;
        
        for(auto x: s){
            if(x!='*'){
                ans.push(x);
            } else {
                ans.pop();
            }
        }
        string sol = "";
        /*

        // This is an expensive alternative 

        while(!ans.empty()){
            sol = ans.top() + sol;
            ans.pop();
        } */

        while(!ans.empty()){
            sol.push_back(ans.top());
            ans.pop();
        } 

        reverse(sol.begin(), sol.end());
        return sol;
    }
};

/*

LEARNING:

When you use ans = st.top() + ans, for every iteration of the while loop, you are creating a new string by concatenating the current character with the existing string. This new string is then assigned to the ans variable. As the size of the string increases, this operation becomes increasingly expensive, resulting in a TLE for larger inputs.

On the other hand, using ans.push_back(st.top()) simply adds the current character to the end of the existing string without creating a new one. This operation is much faster and efficient, as it only modifies the existing string and does not create a new one.

Therefore, using ans.push_back(st.top()) and reversing the string before returning it is a better approach than using sol = ans.top() + sol

*/

