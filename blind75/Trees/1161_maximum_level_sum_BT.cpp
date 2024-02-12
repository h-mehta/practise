
/*

Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

1161. Maximum Level Sum of a Binary Tree

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return -1;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int counter = 1;

        int max_level_sum = INT_MIN;
        int max_level = 0;
        int curr_level_sum = 0;
        int curr_level = 1;

        while(!q.empty()){
            TreeNode* curr_node = q.front();
            q.pop();

            curr_level_sum += curr_node->val;

            if(curr_node->left != nullptr){
                q.push(curr_node->left);
            }
            if(curr_node->right != nullptr){
                q.push(curr_node->right);
            }
            counter--;
            if(counter==0){
                if(curr_level_sum > max_level_sum){
                    max_level_sum = curr_level_sum;
                    max_level = curr_level; 
                }
                counter = q.size();
                curr_level_sum = 0;
                curr_level++;
            }
        }
        return max_level;
    }
};

/*

Learning:

Realisation that
In BFS, when we reach the end of a level, then we a queue in hand that contains all the children at next level in the queue

E.g.
At end of level 2 ----> the queue size will denote number of children in level 3 -> set it to counter

*/

