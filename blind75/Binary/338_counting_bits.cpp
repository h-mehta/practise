

// Link: https://leetcode.com/problems/counting-bits/description/
/* Description: 

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++){
            uint32_t temp = i;
            int counter = 0;
            int mask = 1;
            for(int j=0; j<32; j++){
                if(mask&temp){
                    counter++;
                }
                temp = temp >> 1;
            }
            ans.push_back(counter);
        }
        return ans;
    }
};

