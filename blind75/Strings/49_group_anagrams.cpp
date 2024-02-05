
// Link: https://leetcode.com/problems/group-anagrams/description/
/* Description:

49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

#include<unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int counter = 0;
        int val_assgn = 0;
        unordered_map<string, int> dict;
        vector<vector<string>> ans;
        for(auto x : strs){
            sort(x.begin(), x.end());
            if(dict.contains(x)){
                int val = dict[x];
                ans[val].push_back(strs[counter]);
            } else {
                dict[x] = val_assgn;
                val_assgn++;
                vector<string> temp;			// STAR 1
                temp.push_back(strs[counter]);
                // ans.push_back(temp);			// STAR 2
		ans.push_back( std::move(temp) );
            }
            counter++;
        }
        return ans;
    }
};


/*
Learnings:

REFER STAR 1 line

Temp is created as a vector - the temp variable is stored on the function stack but since vector is dynamically allocated,

temp stores pointer to the dynamic contigous memory on the heap.

If the memory allocated on heap runs out, another larger contigous memory is re-allocated.


That is about the way vectors are managed

REFER STAR 2

when we do ans.push_back(temp) ---> contents of temp vector get copied to ans

Thats why even after going out of scope also, ans has contents of temp

however, 

when we do std::move(temp) the ownership of the memory location pointed to by temp is transfered to ans

This is a much more efficient way to do things!!!!!!

*/
