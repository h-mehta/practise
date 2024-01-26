
/*

Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct Compare{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2 ){
            return p1.first > p2.first;
        }
    };

    unordered_map<int, int> dict;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(ListNode* temp_header: lists){
            ListNode* temp_ptr = temp_header;
            while(temp_ptr!=nullptr){
                dict[temp_ptr->val]++;
                temp_ptr = temp_ptr->next;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for(pair<int, int> temp_pair: dict){
            pq.push(temp_pair);
        }

        ListNode* header = nullptr;
        ListNode* last_node = nullptr;
        while(!pq.empty()){
            pair<int, int> temp_pair = pq.top();
            if(header==nullptr){
                header = new ListNode(temp_pair.first);
                last_node = header;
                temp_pair.second--;
            }
            while(temp_pair.second!=0){
                last_node->next = new ListNode(temp_pair.first);
                temp_pair.second--;
                last_node = last_node->next;
            }
            pq.pop();
        }
        return header;
    }
};


/*

Learnings:

1. Custom priority queues - In C++ we need to make custom compare function if we want to make a priority queue for a User defined data type

2. The syntax for priority queue is:

	In-Built data type:

		priority_queue< int > pq;

	User defined data type:

		priority_queue< datatype_T , container_to_store_elements_of_datatype_T , comaprison_functor > pq;

		Example:

 			priority_queue< int , vector<int>, Compare> pq;

			Notes:
			
				Data type here is int but I do not want to store the int elements on the basis of their values
				Hence I need to make custom compare_functor

				What is a functor?

					Functor in C++ is a struct or class that overloads "operator()"

				- Use a functor otherwise can also make a function and pass a pointer to the function as 3rd argument to 
				  priority_queue but that gets cumbersome ; need to use "decltype" for that

				- In the overloaded "operator()" function specify how to compare 2 elements
				
				  But remember that priority_queue actuals pops the greatest value first i.e. it outputs the least priority 
				  element first ... So design accordingly

				  For example,

					If you want a min-heap, we want to design the operator() such that it returns true when 1st argument
					is smaller.

					Even though that would make a min heap, C++ implementation of priority_queue would first output/pop element with 
					least priority first - thus it will output the data in max-heap format actually (I know its a bit counter intuitive)

					So the following should give min-heap:

						bool operator() ( const pair<int, int>& p1, const pair<int, int>& p2) {
							p1.second < p2.second;
						}

					Because function gives more priority to p1 when p1.second is smaller (Always design the function keeping in mind the 
					priority thats gets assigned to first argument)

					However we would get a Max-heap - weird design of C++ STL priority_queue - so just flip from "<" to ">"

					Keep in mind to reverse it
*/

