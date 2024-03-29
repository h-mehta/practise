
// Link: https://leetcode.com/problems/valid-anagram/description/
/* Description:

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char, int> dict;
        for(int i=0; i<s.size(); i++){
            if(dict.contains(s[i])){
                dict[s[i]]++;
            } else {
                dict[s[i]] = 1;
            }
        }

        for(int i=0; i<t.size(); i++){
            if(dict.contains(t[i])){
                dict[t[i]]--;
            } else {
                return false;
            }
        }
        for(auto p: dict){
            if(p.second!=0){
                return false;
            }
        }
        return true;
    }
};


