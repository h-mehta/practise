/*

Link:

347. Top k Frequent elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/


#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int> dict;

    bool compare(const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int i: nums){
            dict[i]++;
        }
        //priority_queue< pair<int, int>, vector< pair<int, int>>, decltype(&Solution::compare)*> pq(&compare);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(&Solution::compare)*> pq(&compare);

        for(pair<int, int> temp: dict){
            pq.push(temp);
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};



