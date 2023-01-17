using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
  LinkedList *start = linkedList;
  LinkedList *curr_ptr = linkedList;
  int temp = linkedList->value;
  
  while(start!=nullptr){
      if(temp == start->value){
        start = start->next;
        curr_ptr->next = NULL;
      }else{
        curr_ptr->next = start;
        curr_ptr = start;
        temp = start->value;
        start = start->next;
      }
  }
  
  return linkedList;
}

