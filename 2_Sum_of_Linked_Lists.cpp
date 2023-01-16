
/*

Given two Linked Lists of potentially unequal length, where each LL represents a non-negative integer, and the first node in each LinkedList always represents the least significant digit of the integer. Make a LL that represents the sum of the two numbers.

Example:
LL1 = 2 -> 4 -> 7 -> 1  // 1742
LL2 = 9 -> 4 -> 5 	// 549

// Answer : 1742 + 549 = 2291

Ouput List = 1 -> 9 -> 2 -> 2

*/


using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
 
  // Write your code here.

  LinkedList *header = new LinkedList(0);
  LinkedList *curr_ptr = header;
  
  LinkedList *wptr1 = linkedListOne;
  LinkedList *wptr2 = linkedListTwo;

  int num1=0, num2=0, num3=0;
  int counter1 = 0, counter2 = 0;
  
  
  while( wptr1!= nullptr){
        int temp1 = pow(10,counter1);
        counter1++;
        temp1 = wptr1->value*temp1;
        num1 += temp1;
        wptr1 = wptr1->next;
  }

  while( wptr2!= nullptr){
        int temp2 = pow(10,counter2);
        counter2++;
        temp2 = wptr2->value*temp2;
        num2 += temp2;
        wptr2 = wptr2->next;
  }

  num3 = num1 + num2;
  //cout << num1<<"\t"<<num2<<"\t"<< num3;
  header->value = num3%10;
  num3 = num3/10;
  
  while(num3!=0){
      int temp = num3%10;
      LinkedList *temp_ptr = new LinkedList(temp);
      temp_ptr->next = nullptr;

      curr_ptr->next = temp_ptr;
      curr_ptr = temp_ptr;
      num3 = num3/10;
  }
  
  return header;
}
