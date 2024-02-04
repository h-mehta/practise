
// Link : https://leetcode.com/problems/sum-of-two-integers/description/

/* Description:

371. Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000

*/ 

class Solution {
public:
    int getSum(int a, int b) {
        
        int answer = 0;
        int counter = 0;
        int mask = 1;
        unsigned int temp1;
        unsigned int temp2;
        int carry = 0;

        while( a!=0 || b!= 0 || carry!= 0 ){
            temp1 = temp2 = 0;

            temp1 = a & mask;
            temp2 = b & mask;
            if(carry == 0){
                if( temp1 == 1 && temp2 == 1){
                    carry = 1;
                } else if ( temp1 == 1 || temp2 == 1){
                    unsigned int update = 1;
                    update = 1 << counter;
                    answer = answer | update;
                } 
            } else {
                if(temp1 == 0 && temp2 == 0){
                    unsigned int update = 1;
                    update = 1 << counter;
                    answer = answer | update;
                    carry = 0;
                }
                else if(temp1 == 1 && temp2 == 1){
                    unsigned int update = 1;
                    update = 1 << counter;
                    answer = answer | update;
                } else {
                    // carry stays as 1
                }
            }

            a = a>>1;
            b = b>>1;
            counter++;
            if(counter>31){
                break;
            }
        }
        return answer;
    }
};


