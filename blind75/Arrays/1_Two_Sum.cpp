/*

Link: https://leetcode.com/problems/two-sum/description/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]



Solution :
--------
*/

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;

        // Step 1: Store all elements in a hashmap - NOT using hashset because we need index of element aswell
        // Using hashmap as it has O(1) lookup time complexity
        // Moreover we also need to store the index of the element
        unordered_map<int, int> dict;

        for(int i=0; i<nums.size(); i++){
            dict[ nums[i] ] = i;
        }

        // Step 2: Traverse through the nums list - check if target-nums[i] exists in the Hashmap
        for(int i=0; i<nums.size(); i++){
            
            if( dict.count(target-nums[i]) > 0 ){
                if(dict[target-nums[i]] == i){
                    // We do not want same element to be picked twice
                    // Moreover, it is given there is exactly one solution
                    // Thus a case like 3,3,3 does not arise for a target like 6
                    // thus we can be sure that in case of repeated number also,
                    // number will be repeated twice at max
                    // in which dict will have index of second occurence
                    continue;
                }
                ans.push_back(i);
                ans.push_back(dict[target-nums[i]]);
                break;
            }
        }

        return ans;

        // Solution has O(n) complexity 
    }
};


/*

Learnings:
---------

1. Use Hashmap ( unordered_map ) or set ( unordered_set ) for faster lookup - lookup is only O(1) time complexity
      
*/
